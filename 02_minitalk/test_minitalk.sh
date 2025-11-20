#!/bin/bash

// to run ./test_minitalk.sh <server pid> 

PID=$1

if [ -z "$PID" ]; then
    echo "Usage: ./test_minitalk.sh <SERVER_PID>"
    exit 1
fi

echo "===== MINITALK TEST SCRIPT ====="
echo "Testing server PID: $PID"
echo ""

run_test() {
    MSG="$1"
    DESC="$2"

    echo "---- $DESC ----"
    echo "Sending: \"$MSG\""
    ./client $PID "$MSG"
    sleep 0.1
}

echo ""
echo "===== BASIC TESTS ====="
run_test "Hello" "Basic message"
run_test "World" "Second basic message"
run_test "42" "Number test"

echo ""
echo "===== EMPTY STRING TEST ====="
run_test "" "Empty string (should output a blank newline)"

echo ""
echo "===== SPECIAL CHARACTERS ====="
run_test "!@#$%^&*()_+-=~\`" "ASCII special characters"
run_test "Hello, world!? 42 ^_^" "Mixed punctuation"
run_test "Backslash: \\\\ Double Quote: \\\"" "Escaped characters"

echo ""
echo "===== WHITESPACE TESTS ====="
run_test "     " "Five spaces"
run_test "Line\nBreak" "String with newline literal (interpreted by shell)"

echo ""
echo "===== SHORT STRINGS SEQUENCE ====="
for i in {1..5}
do
    run_test "msg_$i" "Sequential short message $i"
done

echo ""
echo "===== LONG MESSAGE (500 chars) ====="
LONG_MSG=$(printf 'A%.0s' {1..500})
run_test "$LONG_MSG" "Long 500-char message"

echo ""
echo "===== LONG MESSAGE (1000 chars) ====="
LONG_MSG2=$(printf 'B%.0s' {1..1000})
run_test "$LONG_MSG2" "Long 1000-char message"

echo ""
echo "===== RANDOM LENGTH MESSAGES ====="
for i in {1..10}
do
    LEN=$(( (RANDOM % 50) + 1 ))
    RANDMSG=$(cat /dev/urandom | tr -dc 'A-Za-z0-9' | head -c $LEN)
    run_test "$RANDMSG" "Random message length $LEN"
done

echo ""
echo "===== MULTIPLE CLIENTS (SEQUENTIAL, FAST) ====="
for i in {1..10}
do
    ./client $PID "client_sequence_$i" &
    sleep 0.05
done
wait

echo ""
echo "===== DONE ====="

echo ""
echo "===== EMOJI TESTS ====="
run_test "😊" "Single emoji (UTF-8 multi-byte, will print as garbage)"
run_test "🚀✨🔥" "Multiple emojis"
run_test "lol 😂🤣😭 omg" "Mixed ASCII and emoji"
run_test "❤️🧡💛💚💙💜" "Colored hearts"

echo "===== DONE ====="
