#!/bin/bash

EXEC=convert
MAKE_CMD="make re"
FAILED_LOG="failed_tests.log"

# ----------------- Testler ------------------

declare -A TESTS=(
    ["127"]="char: Non displayable"
    ["31"]="char: Non displayable"
    ["32"]="char: ' '"
    ["3.5e+38f"]="float: inf"
    ["1e-320"]="double: 1e-320"
    ["0.123456789f"]="float: 0.123457f"
    ["0.123456789123456789"]="double: 0.123457"
    ["+42.0.0"]="Error"
    ["nan"]="float: nanf"
    ["NANF"]="float: nanf"
    [" 42"]="int: 42"
    ["-42"]="int: -42"
    ["+42"]="int: 42"
    ["0"]="int: 0"
    ["1"]="int: 1"
    ["12345678901234567890"]="Error"
    ["-1.23456789"]="float: -1.23457f"
    ["42.0"]="float: 42.0f"
    ["+42.1234"]="float: 42.1234f"
    ["-42.1234"]="float: -42.1234f"
    ["0.0"]="float: 0.0f"
    ["00042"]="int: 42"
    ["3.14159"]="float: 3.14159f"
    ["2.71828"]="float: 2.71828f"
    ["4e-10"]="float: 4e-10f"
    ["42."]="float: 42.0f"
    ["-inf"]="double: -inf"
    ["+inf"]="double: inf"
    ["inf"]="double: inf"
    ["-inff"]="float: -inff"
    ["+inff"]="float: inff"
    ["inff"]="float: inff"
    ["nanf"]="float: nanf"
    ["   42"]="int: 42"
    ["42 42"]="Error"
    [" 3.14 "]="float: 3.14f"
    ["$'\t'42"]="int: 42"
    ["42$'\n'"]="int: 42"
    ["42!"]="Error"
)

# ----------------- Renkler ------------------

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

# ----------------- Derleme ------------------

echo "🔄 Running make re..."
$MAKE_CMD > /dev/null 2>&1

if [ ! -f "$EXEC" ]; then
    echo -e "${RED}❌ Error: Executable '$EXEC' could not be created.${NC}"
    exit 1
fi

echo -e "${GREEN}✔️ Build succeeded. Running tests...${NC}"
echo
> "$FAILED_LOG"

# ----------------- Test Döngüsü ------------------

pass=0
fail=0
i=1

for input in "${!TESTS[@]}"; do
    expected="${TESTS[$input]}"
    
    # Gerçek inputu düzgün parse etmek için eval ile çalış
    eval actual_input=\"${input}\"

    output=$(./$EXEC "$actual_input" 2>&1)

    if echo "$output" | grep -Fq "$expected"; then
        echo -e "${GREEN}✔️ Test $i [$input]: OK${NC}"
        ((pass++))
    else
        echo -e "${RED}❌ Test $i [$input]: KO${NC}"
        echo -e "${YELLOW}   ↳ Beklenen: \"$expected\"${NC}"
        echo -e "   ↳ Alınan:\n$output\n"
        ((fail++))
        {
            echo "Test $i"
            echo "Input   : $input"
            echo "Beklenen: $expected"
            echo "Alınan  :"
            echo "$output"
            echo "----------------------------"
        } >> "$FAILED_LOG"
    fi
    ((i++))
done

# ----------------- Sonuç Özeti ------------------

echo "=========================="
echo -e "✅ Passed: ${GREEN}$pass${NC} / ${#TESTS[@]}"
echo -e "❌ Failed: ${RED}$fail${NC} / ${#TESTS[@]}"
echo "=========================="

if [ $fail -gt 0 ]; then
    echo -e "${YELLOW}🔍 Detaylar için '$FAILED_LOG' dosyasına bakabilirsiniz.${NC}"
else
    echo -e "${GREEN}🎉 Tüm testler başarıyla geçti!${NC}"
fi
