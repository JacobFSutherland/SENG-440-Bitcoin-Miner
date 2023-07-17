#!/bin/bash

set -o pipefail

PROGRAM=./sha256_test

function fail() {
  echo -n -e '\e[1;31m[ERROR]\e[0m '
  echo -e "$1"
  exit 1
}

function do_run() {
  {
    IFS=$'\n' read -r -d '' stderr;
    IFS=$'\n' read -r -d '' output;
  } < <((printf '\0%s\0' "$($PROGRAM "$2")" 1>&2) 2>&1)
  # output=$(eval "$PROGRAM $2")

  expected=$(echo -n $3 | xxd -r -p)

  if [ "$output" != "$expected" ]; then
    echo FAILED
    expected_hex=$(echo -n "$expected" | xxd -p -c 1000000000)
    actual_hex=$(echo -n "$output" | xxd -p -c 1000000000)
    
    msg="expected:\n$expected_hex\nbut got:\n$actual_hex"
    if [ "$stderr" != "" ]; then
      msg="$msg\nstderr:\n$stderr"
    fi
    fail "$msg"
  fi
}

function run() {
  echo -n "Testing $1 ... "
  do_run "$@"
  echo ok
}

run empty "" e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855
run letter a ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb
run short 'hello, bitcoin!' 805626ab387601ac3e380fce945c09e04dbe96c4c493d43fd2e5876647b8064f
run full_block 'bitconnect is the best exchange ever I love bitconnect!' bfcb0f73b7b17d4b8bd1c46f640d4d91afc8d930cd4e525619482d05e497a6fd
run one_past_block 'bitconnect is the best exchange ever I love bitconnect!!' 6520eb721bb8351bca128544aa3240d36985e267e8fd8a24189ad17afa7ad284
run fill_first_block 'the quick brown fox jumped over the lazy dog. i love most dogs!' 90d1632dc6d031f28e30e734cd610394cf8497d0d1358cc5bdabb0cd92cc86b4
run overflow_first_block 'the quick brown fox jumped over the lazy dog. i love most dogs!!' 29bb3dabe9330dd6cc319c3187a43f0d800a45ae973e958b9d81e3b6a9bea802
run lorem_ipsum 'Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industrys standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.' 1f5d66dc8af2587ac74e50eae32957087290a2414245bbf2c190ff488b0c114f
