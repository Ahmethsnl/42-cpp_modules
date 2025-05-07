#!/bin/bash

EXEC=convert
MAKE_CMD="make re"
FAILED_LOG="failed_tests.log"

TESTS=(
    "127"                      # Upper bound of ASCII characters
    "31"                       # Lower bound of ASCII printable characters
    "32"                       # Space
    "3.5e+38f"                 # Float with scientific notation
    "1e-320"                   # Very small float
    "0.123456789f"             # Precision float
    "0.123456789123456789"     # Precision double
    "+42.0.0"                  # Invalid float format
    "NaN"                      # Special case for NaN
    "nan"                      # Special case for nan
    "NANF"                     # Special case for nanf
    " 42"                      # Float with leading space
    "-42"                      # Negative integer
    "+42"                      # Positive integer with +
    "0"                        # Zero
    "1"                        # Integer 1
    "12345678901234567890"     # Large integer
    "-1.23456789"              # Negative float
    "42.0"                     # Normal float
    "+42.1234"                 # Positive float with decimal
    "-42.1234"                 # Negative float with decimal
    "0.0"                      # Zero float
    "00042"                    # Integer with leading zeros
    "3.14159"                  # Pi float
    "2.71828"                  # Euler's number float
    "4e-10"                    # Small scientific float
    "42."                      # Invalid float format with dot at the end
    "-inf"                     # Negative infinity (double)
    "+inf"                     # Positive infinity (double)
    "inf"                      # Infinity (double)
    "-inff"                    # Negative infinity (float)
    "+inff"                    # Positive infinity (float)
    "inff"                     # Infinity (float)
    "nanf"                     # NaN (float)
    "   42"                    # Integer with leading space
    "42 42"                    # Invalid input: multiple values
    " 3.14 "                   # Float with trailing spaces
    "\t42"                     # Tab before number
    "42\n"                     # Newline after number
    "42!"                      # Invalid character after number
)

EXPECTED_OUTPUTS=(
    "char: Non displayable"      # 127
    "char: Non displayable"      # 31
    "char: ' '"                  # 32
    "float: inf"                 # 3.5e+38f
    "double: 1e-320"             # 1e-320
    "float: 0.123457f"           # 0.123456789f
    "double: 0.12345678912345678"# 0.123456789123456789
    "Error"                      # +42.0.0
    "Error"                      # NaN
    "float: nanf"                # nan
    "float: nanf"                # NANF
    "int: 42"                    # 42 (başında boşluk)
    "int: -42"                   # -42
    "int: 42"                    # +42
    "int: 0"                     # 0
    "int: 1"                     # 1
    "int: 12345678901234567890"  # Large number (might be truncated to int max or invalid)
    "float: -1.234568f"          # -1.23456789
    "float: 42.0f"               # 42.0
    "float: 42.123400f"          # +42.1234
    "float: -42.123400f"         # -42.1234
    "float: 0.0f"                # 0.0
    "int: 42"                    # 00042
    "float: 3.141590f"           # Pi
    "float: 2.718280f"           # Euler's number
    "float: 4e-10f"              # Small float
    "Error"                      # 42. (dot at the end)
    "double: -inf"               # -inf
    "double: inf"                # +inf
    "double: inf"                # inf
    "float: -inff"               # -inff
    "float: inf"                 # +inff
    "float: inf"                 # inff
    "float: nanf"                # nanf
    "int: 42"                    # leading space
    "Error"                      # multiple values
    "float: 3.14f"               # float with trailing space
    "int: 42"                    # tab before number
    "int: 42"                    # newline after number
    "Error"                      # invalid character after number
)

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo "🔄 Running make re..."
$MAKE_CMD > /dev/null 2>&1

if [ ! -f "$EXEC" ]; then
    echo -e "${RED}❌ Error: Executable '$EXEC' could not be created.${NC}"
    exit 1
fi

echo -e "${GREEN}✔️ Build succeeded. Running tests...${NC}"
echo

# Clear previous log
> "$FAILED_LOG"

pass=0
fail=0

for i in "${!TESTS[@]}"; do
    input="${TESTS[$i]}"
    expected="${EXPECTED_OUTPUTS[$i]}"
    
    output=$(./$EXEC "$input" 2>&1)
    if echo "$output" | grep -qi "$expected"; then
        echo -e "${GREEN}✔️ Test $((i+1)) [$input]: OK${NC}"
        ((pass++))
    else
        echo -e "${RED}❌ Test $((i+1)) [$input]: KO${NC}"
        echo -e "${YELLOW}   ↳ Expected: \"$expected\"${NC}"
        echo -e "   ↳ Got:\n$output\n"
        ((fail++))
        # Log to file
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

echo "=========================="
echo -e "✅ Passed: ${GREEN}$pass${NC} / ${#TESTS[@]}"
echo -e "❌ Failed: ${RED}$fail${NC} / ${#TESTS[@]}"
echo "=========================="

if [ $fail -gt 0 ]; then
    echo -e "${YELLOW}🔍 See detailed failed test output in '$FAILED_LOG'${NC}"
fi

if [ $fail -eq 0 ]; then
    echo -e "${GREEN}🎉 All tests passed!${NC}"
else
    echo -e "${RED}🚨 Some tests failed!${NC}"
fi