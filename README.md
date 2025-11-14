## Project 5 - Empirical Analysis of Batch-then-Drain Profile

## Student Information
Parker Tennier  
ID: 008768156  
https://github.com/tennierp/priority-queue-empirical-analysis.git

## Collaboration & Sources
Dr. Ali A. Kooshesh provided all of the benchmark tools necessary to run this program as well as the data structure implementations: BinaryHeapInVector, BinomialQueues, LinearBaseline, Oracle. The project was built from his original Empirical Analysis of Huffman Profiles project. I also used a pdf-to-markdown converter to help me better organize my pdf report into a markdown file. 

## Implementation Details
### Trace Generator
The batch-then-drain trace generator creates traces following the same conventions as the Huffman Profile. The profile performs N insert operations and then N deleteMin operations. Keys are randomly generated between 1 and 2^20 to minimize the amount of duplicates across the trace files. Each trace file has a header line with the profile name, N value, and the seed that was used, followed by the operation lines for the harness.

- `I <key> <id>` for insert operations
- `D` for deleteMin operations.

All traces are currently using seed 23 for reproduction, change this seed for different results.

### Harness
The harness was modified to accept a command-line argument specifying which profile to run, either the batch_then_drain or huffman_coding, allowing both generated trace files to be used separately.

The harness runs one untimed warmup run followed by the timed trials. It then gives a median result of these elapsed time in ms. The Oracle was only timed up to N = 2^15 to avoid a longer runtime than needed.

## Testing & Status
This benchmark tests the Binary Heap, Binomial Queue, a Linear Baseline, and a Quadratic Oracle. The batch-then-drain will properly generate 12 trace files with a random key value. After generating the trace files, the harness will cycle through those generated trace files and create a csv file at the end of it's runtime. The result csv file may be used in the `charts\pq_multi_impl_anchor_heap_tooltips.html` html chart to see the results of the Harness.

## Commands
### Generate batch-then-drain trace files
```bash
make batch
```
This will generate the Trace files into the `traces/batch_then_drain/` directory.

### Run Harness on batch-then-drain traces
```bash
make runbatch
```
This will run Harness on the batch-then-drain generated trace files and output a csv file into `csvs/batchThenDrainProfile.csv` after it has finished running.
You must first create the batch-then-drain trace files before running this command.

### Generate Huffman trace files
```bash
make huffman
```
This will generate the Trace files into the `traces/huffman_coding/` directory.

### Run Harness on huffman traces
```bash
make runhuffman
```
This will run Harness on the Huffman generated trace files and output a csv file into `csvs/huffmanProfile.csv` after it has finished running.
You must first create the Huffman trace files before running this command.

### Cleanup
```bash
make clean
```
This will delete all .csv and .trace files for a fresh start.
