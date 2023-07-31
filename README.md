# SENG-440-Bitcoin-Miner

This is the repo for our SENG 440 Bitcoin miner project.

## Usage

To run the tests, Make and GCC are needed.

```console
$ ./test.sh
$ # or
$ cd src/naive/
$ make clean && make release
$ ./test_main.sh
$ ./test_sha256.sh
```

To benchmark, `hyperfine` is also needed

```console
$ ./benchmark.sh # for -O0 unoptimized
$ ./benchmark.sh # for -O3 optimized (minus SIMD since its broken)
```

If you would like to run the programs individually, there are the following binaries for each version:

```console
Usage: ./main <difficulty> <input> <iterations>
  difficulty: number of leading zeros in the hash
  input: the hash of the genesis block (in hex)
  iterations: the number of blocks you want to solve
```

```console
Usage: ./sha256_benchmark <input_len> <iterations>
  input_len: length of input
  iterations: number of iterations
```

This one isn't supposed to be run by users, since the input and output are binary data rather than hex, but `sha256_test` is used by `test_sha256.sh`