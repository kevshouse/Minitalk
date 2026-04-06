#!/bin/bash
SERVER_PID=$1
# Generate random strings of increasing lengths
for i in {1..10}; do
    LEN=$((i * 500))
    STR=$(python3 -c "import string, random; print(''.join(random.choices(string.ascii_letters, k=$LEN)))")
    echo "Testing length $LEN..."
    ./client_exec $SERVER_PID "$STR"
    sleep 0.5
done