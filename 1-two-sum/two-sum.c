#include <stdlib.h>

#define HASH_SIZE 20011  // prime larger than 2 * 10^4

typedef struct {
    int key;
    int value;
    int used;
} Entry;

static Entry hashTable[HASH_SIZE];

static int hashFunc(int key) {
    int h = key % HASH_SIZE;
    if (h < 0) h += HASH_SIZE;
    return h;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // Clear the hash table for this call
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i].used = 0;
    }
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int h = hashFunc(complement);
        
        // Search for complement using linear probing
        while (hashTable[h].used) {
            if (hashTable[h].key == complement) {
                result[0] = hashTable[h].value;
                result[1] = i;
                return result;
            }
            h = (h + 1) % HASH_SIZE;
        }
        
        // Insert current number with its index
        h = hashFunc(nums[i]);
        while (hashTable[h].used) {
            h = (h + 1) % HASH_SIZE;
        }
        hashTable[h].key = nums[i];
        hashTable[h].value = i;
        hashTable[h].used = 1;
    }
    
    return result;
}