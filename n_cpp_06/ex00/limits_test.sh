#!/bin/bash

EXEC=./convert
MAKE_CMD="make re"
FAILED_LOG="float_double_limits_failures.log"

TESTS=(
    # FLOAT UNDERFLOW
    "1e-46"
    "5e-46"
    "1e-44"

    # FLOAT LOWER LIMIT
    "1.4013e-45"   # smallest positive subnormal float
    "1.17549e-38"  # smallest positive normal float

    # FLOAT OVERFLOW
    "3.5e+38"
    "1e+39"

    # DOUBLE UNDERFLOW
    "1e-324"
    "2e-324"

    # DOUBLE LOWER LIMIT
    "4.9e-324"      # smallest positive subnormal double
    "2.22507e-308"  # smallest positive normal double

    # DOUBLE OVERFLOW
    "1.8e+308"
    "1e+309"
)

EXPECTED_OUTPUTS=(
    # FLOAT UNDERFLOW
    "float: 0.0f"
    "float: 0.0f"
    "float: 9.80909e-45f"

    # FLOAT LOWER LIMIT
    "float: 1.4013e-45f"
    "float: 1.17549e-38f"

    # FLOAT OVERFLOW
    "float: +inf"
    "float: +inf"

    # DOUBLE UNDERFLOW
    "double: 0.0"
    "double: 0.0"

    # DOUBLE LOWER LIMIT
    "double: 0.0"
    "double: 2.22507e-308"

    # DOUBLE OVERFLOW
    "double: +inf"
    "double: +inf"
)

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

# Make re
echo -e "${YELLOW}🔄 Building project with make re...${NC}"
$MAKE_CMD > /dev/null 2>&1

if [ ! -f "$EXEC" ]; then
    echo -e "${RED}❌ Error: Executable '$EXEC' not found.${NC}"
    exit 1
fi

# Clean log
> "$FAILED_LOG"
pass=0
fail=0

echo -e "${GREEN}🚀 Running float/double limit tests...${NC}"

for i in "${!TESTS[@]}"; do
    input="${TESTS[$i]}"
    expected="${EXPECTED_OUTPUTS[$i]}"

    output=$($EXEC "$input" 2>&1)

    if echo "$output" | grep -q "$expected"; then
        echo -e "${GREEN}✔️ Test $((i+1)) [$input] → OK${NC}"
        ((pass++))
    else
        echo -e "${RED}❌ Test $((i+1)) [$input] → KO${NC}"
        echo -e "${YELLOW}   ↳ Expected: $expected${NC}"
        echo -e "   ↳ Got:\n$output\n"
        ((fail++))

        {
            echo "Test $((i+1))"
            echo "Input   : $input"
            echo "Expected: $expected"
            echo "Got     :"
            echo "$output"
            echo "----------------------------"
        } >> "$FAILED_LOG"
    fi
done

echo
echo "=========================="
echo -e "✅ Passed: ${GREEN}$pass${NC} / ${#TESTS[@]}"
echo -e "❌ Failed: ${RED}$fail${NC} / ${#TESTS[@]}"
echo "=========================="

if [ $fail -gt 0 ]; then
    echo -e "${YELLOW}🔍 See details in $FAILED_LOG${NC}"
else
    echo -e "${GREEN}🎉 All float/double limit tests passed!${NC}"
fi
