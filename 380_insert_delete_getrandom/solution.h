#pragma once

#include <memory>
#include <random>
#include <stdexcept>
#include <utility>

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedSet
{
public:
    RandomizedSet()
        : state(new State(8, std::random_device()()))
    {
    }

    bool insert(int val)
    {
        rehashIfNeeded();
        return state->insert(val);
    }

    bool remove(int val)
    {
        return state->remove(val);
    }

    int getRandom()
    {
        return state->getRandom();
    }

private:
    void rehashIfNeeded()
    {
        if (2 * state->usedItemsCount < state->items.size())
        {
            return;
        }
        std::unique_ptr<State> newState(new State(state->items.size() * 2, 0));
        for (const Item& item : state->items)
        {
            if (item.state == ItemState::Used)
            {
                newState->insert(item.value);
            }
        }
        std::swap(state, newState);
    }

    enum class ItemState
    {
        Unused,
        Used,
        Erased,
    };

    struct Item
    {
        ItemState state = ItemState::Unused;
        int value = 0;
    };

    struct State
    {
        size_t usedItemsCount = 0;
        std::vector<Item> items;
        std::mt19937 generator;
        std::uniform_int_distribution<> distribution;

        State(size_t size, std::random_device::result_type seed)
            : items(size, Item{})
            , generator(seed)
            , distribution(0, size - 1)
        {
        }

        bool insert(int val)
        {
            size_t size = items.size();
            size_t position = std::hash<int>{}(val) % size;
            size_t i = position;
            do
            {
                if (items[i].state != ItemState::Used)
                {
                    items[i] = Item{ ItemState::Used, val };
                    ++usedItemsCount;
                    return true;
                }
                if (items[i].state == ItemState::Used && items[i].value == val)
                {
                    return false;
                }

                i = (i + 1) % size;
            } while (i != position);

            throw std::logic_error("cannot insert: hash table is full");
        }

        bool remove(int val)
        {
            size_t size = items.size();
            size_t position = std::hash<int>{}(val) % size;
            size_t i = position;
            do
            {
                if (items[i].state == ItemState::Unused)
                {
                    return false;
                }
                if (items[i].state == ItemState::Used && items[i].value == val)
                {
                    items[i].state = ItemState::Erased;
                    --usedItemsCount;
                    return true;
                }
                i = (i + 1) % size;
            } while (i != position);

            return false;
        }

        int getRandom()
        {
            size_t size = items.size();
            size_t position = distribution(generator);
            size_t i = position;
            do
            {
                if (items[i].state == ItemState::Used)
                {
                    return items[i].value;
                }
                i = (i + 1) % size;
            } while (i != position);

            throw std::logic_error("cannot find random value: hash table is empty");
        }
    };

    std::unique_ptr<State> state;
};
