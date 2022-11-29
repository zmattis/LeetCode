/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 *
 * Implement the RandomizedSet class:
 *
 *     RandomizedSet()        Initializes the RandomizedSet object.
 *     bool insert(int val)   Inserts an item val into the set if not present.
 *                            Returns true if the item was not present, false otherwise.
 *     bool remove(int val)   Removes an item val from the set if present.
 *                            Returns true if the item was present, false otherwise.
 *     int getRandom()        Returns a random element from the current set of elements.
 *                            It is guaranteed that at least one element exists when this method is called.
 *                            Each element must have the same probability of being returned.
 *
 * You must implement the functions of the class such that each function works
 * in average O(1) time complexity.
 */

// @lc code=start

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

#include <ctime>
#include <random>
#include <vector>
#include <unordered_map>

class RandomizedSet
{
private:
	std::vector<int32_t> rng;
	std::unordered_map<int32_t, int32_t> hm;

public:
	RandomizedSet()
	{
		std::srand(std::time(nullptr));
	}

	bool insert(int32_t val)
	{
		bool exists = (this->hm.find(val) != this->hm.end());
		if (exists) { return false; }

		this->rng.push_back(val);
		this->hm[val] = this->rng.size()-1;
		return true;
	}

	bool remove(int32_t val)
	{
		bool exists = (this->hm.find(val) != this->hm.end());
		if (!exists) { return false; }

		int32_t key = this->rng.back();
		this->hm[key] = this->hm[val];

		this->rng[this->hm[val]] = key;
		this->rng.pop_back();

		this->hm.erase(val);
		return true;
	}

	int32_t getRandom()
	{
		return this->rng[std::rand() % this->rng.size()];
	}
};

// @lc code=end
