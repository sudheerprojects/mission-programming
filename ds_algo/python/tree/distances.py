"""
Implementation of different distances/length involved in BT
"""

from binary_tree import BinaryTree, Node
from bt_utils import BTUtils

class TreeDistances(object):
    def __init__(self):
        pass

    @staticmethod
    def distance_two_nodes(root, n1, n2):
        """distance between n1 and n2 in BT = dist(lca to n1) + dist(lca to n2)
        LCA - lowest common ancestor of n1 and n2
        """
        lca = BTUtils.LCA(root, n1, n2)
        #Utility class will return level with base level 1, hence -2
        return BTUtils.level(lca, n1)+BTUtils.level(lca, n2) - 2

if __name__ == '__main__':
    bt = BinaryTree.from_list( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15])
    bt.pprint()
    print('Distance between 9 and 13 -', end='  ')
    print(TreeDistances.distance_two_nodes(bt.get_root(), 9, 13))
