#!/usr/bin/env python
# -*- encoding:utf-8 -*-
#
# python 3.7
# Student Name: Pujian Yang
# Student Number: 20046229
# "I certify that this submission contains my own work, except as noted."


class Set(object):
    """
    Class Set
    Basic Data Structure That Contains Two Members, Elements and Sum
    """
    def __init__(self, __elements=None, __sum=None, compute=True):
        """
        Default Constructor
        :param __elements: The set elements, could be list, tuple, set of other iterable
        :param __sum: Sum of all the values of elements
        :param compute: Flag indicates whether or not compute the sum in current set object
        """
        self.__elements = __elements if __elements is not None else []
        self.__sum = 0 if __elements is None or compute is False else __sum if __sum is not None else sum(__elements)

    @classmethod
    def clone(cls, _set):
        """
        Copy Constructor
        :param _set: The target set to be copied
        :return: A copy set object of target
        """
        return cls(_set.get_elements(), _set.get_sum())

    @classmethod
    def merge(cls, _set1, _set2):
        """
        Merge Constructor
        :param _set1: The target set to be merged
        :param _set2: The target set to be merged
        :return: A copy set object that has elements and sum from two targets
        """
        return cls(_set1.get_elements() + _set2.get_elements(), _set1.get_sum() + _set2.get_sum())

    def get_sum(self):
        """
        Get Sum Method
        :return: The sum of current set object
        """
        return self.__sum

    def get_elements(self):
        """
        Get Elements Method
        :return: A copy of member elements
        """
        return [_ for _ in self.__elements]

    def split(self):
        """
        Split current set into two new sets
        :return: Two set objects that are divide from the original set object
        """
        n = len(self.__elements)
        return Set(self.__elements[:int(n/2)]), Set(self.__elements[int(n/2):])


# Constant of Empty Set
EMPTY_SET = Set()


#  BFI_Subset_Sum
def bfi_subset_sum(s: Set, k):
    """
    BFI_Subset_Sum
    Brute Force Method of Subset Sum Algorithm (Divide and Conquer)
    :param s: Target set object
    :param k: Target value
    :return:
    """
    if k == 0:
        return EMPTY_SET
    subsets = [EMPTY_SET]  # an empty list of Set objects
    for element in s.get_elements():
        new_subsets = []  # an empty list of Set objects
        for old_u in subsets:
            new_u = Set(old_u.get_elements() + [element], old_u.get_sum() + element)
            if new_u.get_sum() == k:
                return new_u
            else:
                new_subsets.append(old_u)
                new_subsets.append(new_u)
        subsets = new_subsets
    return EMPTY_SET


#  HS_Subset_Sum
def hs_subset_sum(s: Set, k):
    """
    HS_Subset_Sum
    Horowitz/Sahni Algorithm of Subset Sum Algorithm
    :param s: Target set object
    :param k: Target value
    :return: A Set object contains elements that could be added up to the target
    """
    if k == 0:
        return EMPTY_SET
    s_left, s_right = s.split()
    subsets_left, sums_left = get_all_subsets(s_left)
    subsets_right, sums_right = get_all_subsets(s_right)
    if k in sums_left:
        return subsets_left[sums_left.index(k)]
    elif k in sums_right:
        return subsets_right[sums_right.index(k)]
    else:
        subsets_left.sort(key=lambda _: _.get_sum())
        subsets_right.sort(key=lambda _: _.get_sum())
        sums_left.sort()
        sums_right.sort()
        index_left, index_right = pair_sum(sums_left, sums_right, k)
        if index_left != -1 and index_right != -1:
            return Set.merge(subsets_left[index_left], subsets_right[index_right])
    return EMPTY_SET


def get_all_subsets(s: Set):
    """
    Modified BFI Subset Sum function
    Generates all the subsets and
    :param s: Base set object where subsets are generated from
    :return: A list contains all the subsets and the other lists contains all the sum
    """
    subsets = [EMPTY_SET]  # an empty list of Set objects
    for element in s.get_elements():
        new_subsets = []  # an empty list of Set objects
        for old_u in subsets:
            new_u = Set(old_u.get_elements() + [element], old_u.get_sum() + element)
            new_subsets.append(old_u)
            new_subsets.append(new_u)
        subsets = new_subsets
    sums = [_.get_sum() for _ in subsets]
    return subsets, sums


def pair_sum(values_1, values_2, k):
    # Values_1 and Values_2 are sorted
    # indexing starts at 1 because I am a dinosaur
    p1, p2 = 0, len(values_2) - 1
    while p1 < len(values_1) and p2 >= 0:
        t = values_1[p1] + values_2[p2]
        if t == k:
            return p1, p2
        elif t < k:
            p1 += 1
        else:
            p2 -= 1
    return -1, -1


if __name__ == '__main__':
    output = ""
    test_set = Set([3, 5, 3, 9, 18, 4, 5, 6], compute=False)
    targets = [28, sum(test_set.get_elements()), 100]
    for target in targets:
        output += f"Data Source: {test_set.get_elements()}\n"
        output += f"Target: {target}\n"
        output += f"BFI: {(bfi_subset_sum(test_set, target).get_elements())}\n"
        output += f"SH: {hs_subset_sum(test_set, target).get_elements()}\n"
    print(output)
    with open("./output.txt", "w") as out:
        out.write(output)
