#!/bin/bash

set -o pipefail

PROGRAM=./main

function fail() {
  echo -n -e '\e[1;31m[ERROR]\e[0m '
  echo -e "$1"
  exit 1
}

function do_run() {
  output=$(eval "$PROGRAM $2")
  exit_code=$?
  if [ $exit_code -ne 0 ]; then
    echo FAILED
    fail "exit code $exit_code\noutput:\n$output"
  fi

  expected=$(echo -n $3 | xxd -r -p)

  if [ "$output" != "$expected" ]; then
    echo FAILED
    expected_hex=$(echo -n "$expected" | xxd -p -c 1000000000)
    actual_hex=$(echo -n "$output" | xxd -p -c 1000000000)
    fail "expected:\n$expected_hex\nbut got:\n$actual_hex"
  fi
}

function run() {
  echo -n "Testing $1 ... "
  do_run "$@"
  echo ok
}

run empty "10 ''" e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855
run letter "10 'a'" ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb
run short "10 'hello, bitcoin!'" 805626ab387601ac3e380fce945c09e04dbe96c4c493d43fd2e5876647b8064f
run full_block "10 'bitconnect is the best exchange ever I love bitconnect!'" bfcb0f73b7b17d4b8bd1c46f640d4d91afc8d930cd4e525619482d05e497a6fd
run one_past_block "10 'bitconnect is the best exchange ever I love bitconnect!!'" 6520eb721bb8351bca128544aa3240d36985e267e8fd8a24189ad17afa7ad284

