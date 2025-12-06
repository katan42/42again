#!/usr/bin/env bash

GREEN="\033[32m"
RED="\033[31m"
RESET="\033[0m"

pass() { echo -e "${GREEN}PASS${RESET} - $1"; }
fail() { echo -e "${RED}FAIL${RESET} - $1 (got: '$2')"; }

run() {
    desc="$1"
    expected="$2"
    shift 2

    output=$(./push_swap "$@" 2>&1)

    if [[ "$expected" == "ERROR" ]]; then
        if [[ "$output" == "Error" ]]; then pass "$desc"
        else fail "$desc" "$output"; fi
    else
        # expected = OK
        chk=$(./push_swap "$@" | ./checker_linux "$@" 2>&1)
        if [[ "$chk" == "OK" ]]; then pass "$desc"
        else fail "$desc" "$chk"; fi
    fi
}

echo "===== VALID CASES ====="
run "VALID: -0 → interpreted as 0" OK -0
run "VALID: leading zeros" OK 000000012
run "VALID: mixed signs (unique ints)" OK 5 -4 +3

echo
echo "===== DUPLICATES ====="
run "ERROR: 0 and -0 (duplicate)" ERROR 0 -0
run "ERROR: duplicate 12" ERROR 12 99 12

echo
echo "===== FORMATTING ERRORS ====="
run "ERROR: empty string" ERROR ""
run "ERROR: spaces only" ERROR " "
run "ERROR: sign only '+'" ERROR "+"
run "ERROR: sign only '-'" ERROR "-"
run "ERROR: double sign '++3'" ERROR "++3"
run "ERROR: double sign '--3'" ERROR "--3"
run "ERROR: mixed signs '+-3'" ERROR "+-3"
run "ERROR: decimal '3.5'" ERROR "3.5"
run "ERROR: letters 'abc'" ERROR "abc"
run "ERROR: letters inside '12ab'" ERROR "12ab"
run "ERROR: trailing space '3 '" ERROR "3 "

echo
echo "===== OVERFLOW ====="
run "ERROR: above INT_MAX" ERROR 2147483648
run "ERROR: below INT_MIN" ERROR -2147483649
run "ERROR: huge number" ERROR 9999999999999
run "ERROR: huge negative" ERROR -9999999999999

echo
echo "===== MIXED EDGE CASES ====="
run "ERROR: many zeros interpreted as same value" ERROR 0 -0 0000
run "ERROR: quoted list (should NOT split)" ERROR "1 2 3"
run "VALID: individually quoted args" OK "1" "2" "3"

echo
echo "===== RANDOM TESTS ====="

for i in {1..50}
do
    ARG=$(seq -5000 5000 | shuf | head -n 50 | tr '\n' ' ')
    chk=$(./push_swap $ARG | ./checker_linux $ARG)

    if [ "$chk" = "OK" ]; then
        pass "Random $i"
    else
        fail "Random $i"
    fi
done
