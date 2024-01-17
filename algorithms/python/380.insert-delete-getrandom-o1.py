#
# @lc app=leetcode id=380 lang=python3
#
# [380] Insert Delete GetRandom O(1)
#
# Implement the RandomizedSet class:
#
#   • RandomizedSet()        Initializes the RandomizedSet object.
#   • bool insert(int val)   Inserts an item val into the set if not present.
#                            Returns true if the item was not present, false otherwise.
#   • bool remove(int val)   Removes an item val from the set if present.
#                            Returns true if the item was present, false otherwise.
#   • int getRandom()        Returns a random element from the current set of elements
#                            It is guaranteed that at least one element exists when this method is called.
#                            Each element must have the same probability of being returned.
#
# You must implement the functions of the class such that each function works
# in average O(1) time complexity.
#
# Constraints:
#   • -2^31 <= val <= 2^31 - 1
#   • At most 2 * 10^5 calls will be made to insert, remove, and getRandom.
#   • There will be at least one element in the data structure when getRandom is called.
#

# @lc code=start

import random

class RandomizedSet:

    # Complexity:
    #   • Time: O(1)
    #   • Space: O(n)

    def __init__(self) -> None:

        self.rng = []
        self.ht = {}

    def insert(self, val: int) -> bool:

        if val in self.ht:
            return False

        self.ht[val] = len(self.rng)
        self.rng.append(val)

        return True

    def remove(self, val: int) -> bool:

        if val not in self.ht:
            return False

        idx = self.ht[val]
        self.rng[idx] = self.rng[-1]
        self.ht[self.rng[idx]] = idx
        self.rng.pop()
        self.ht.pop(val)

        return True

    def getRandom(self) -> int:

        n = random.randint(0, len(self.rng)-1)
        return self.rng[n]

# @lc code=end
