batch:
	g++ -std=c++20 -o batch_then_drain_trace src/trace-generators/batch_then_drain/main.cpp utils/*.cpp -I utils
	./batch_then_drain_trace

huffman:
	g++ -std=c++20 -o huffman_trace src/trace-generators/huffman_coding/main.cpp utils/*.cpp -I utils
	./huffman_trace

harness:
	g++ -std=c++20 -o harness src/harness/main.cpp src/implementations/BinaryHeapInVector/BinaryHeapInVector.cpp src/implementations/BinomialQueues/BinomialQueue.cpp src/implementations/BinomialQueues/BQnode.cpp src/implementations/LinearBaseLine/LinearBaseLine.cpp src/implementations/Oracle/QuadraticOracle.cpp utils/*.cpp -I utils -I src/implementations

runbatch: harness
	./harness batch_then_drain > csvs/batchThenDrainProfile.csv

runhuffman: harness
	./harness huffman_coding > csvs/huffmanProfile.csv

clean:
	rm -f batch_then_drain_trace huffman_trace harness
	rm -f traces/batch_then_drain/*.trace
	rm -f traces/huffman_coding/*.trace