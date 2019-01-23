#include "solution.h"

#include <benchmark/benchmark.h>

static void BM_CacheGet(benchmark::State& state) {
    LRUCache cache(16);
    cache.put(1, 1);

    int counter {0};
    for (auto _ : state) {

        cache.get(1);
        cache.put(counter, counter);
        counter++;

    }
}

BENCHMARK(BM_CacheGet);


static void BM_CachePut(benchmark::State& state) {
    LRUCache cache(16);

    int counter {0};
    for (auto _ : state) {
        cache.put(counter, counter);
        counter++;
    }
}

BENCHMARK(BM_CachePut);

BENCHMARK_MAIN();