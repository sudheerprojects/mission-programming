"""
Implements algorithms to find different views of binary trees
"""

from binary_tree import BinaryTree, Node

class TreeViews(object):
    def __init__(self):
        pass

    @staticmethod
    def left_view(root, level, max_level):
        """Prints the left view node values
        * Analysis
        - Time Complexity = O(n), every node is visited only once
        - Space Complexity = O(1)
        """

        if root is None:
            return

        if max_level[0] < level:
            print(root.data, end='  ')
            max_level[0] = max_level[0]+1

        TreeViews.left_view(root.left, level+1, max_level)
        TreeViews.left_view(root.right, level+1, max_level)

    @staticmethod
    def right_view(root, level, max_level):
        """Prints the Right view node values
        * Analysis
        - Time Complexity = O(n), every node is visited only once
        - Space Complexity = O(1)
        """

        if root is None:
            return

        if max_level[0] < level:
            print(root.data, end='  ')
            max_level[0] = max_level[0]+1

        TreeViews.right_view(root.right, level+1, max_level)
        TreeViews.right_view(root.left, level+1, max_level)

    @staticmethod
    def __top_view_util(root, distance, height,  distance_map):
        if root is None:
            return root

        #Insert the current node values into list of nodes of given distance
        if distance in distance_map:
            #Insert only if height of node is less than existing elemenet
            if (distance_map[distance])[0] > height:
                distance_map[distance] = (height, root.data)
        else:
            distance_map[distance] = (height, root.data)

        TreeViews.__top_view_util(root.left, distance-1, height+1, distance_map)
        TreeViews.__top_view_util(root.right, distance+1, height+1, distance_map)


    @staticmethod
    def top_view(root ):
        """Prints Top view node values
        *Algo:
        - Top view is elements with lowest level in the list of elements with same horizontal distance
        *Analysis:
        - Time Complexity = O(n), every node is visited only once
        - Space Complexity = O(n)
        """
        distance_map = dict()
        TreeViews.__top_view_util(root, 0, 1, distance_map)

        for k in sorted([i for i in distance_map.keys()]):
            print((distance_map[k])[1],  end='  ')

    @staticmethod
    def __bottom_view_util(root, distance, height,  distance_map):
        if root is None:
            return root

        #Insert the current node values into list of nodes of given distance
        if distance in distance_map:
            #Insert only if height of node is greter than or equal existing elemenet
            if (distance_map[distance])[0] <=  height:
                distance_map[distance] =(height, root.data)
        else:
            distance_map[distance] = (height, root.data)

        TreeViews.__bottom_view_util(root.left, distance-1, height+1, distance_map)
        TreeViews.__bottom_view_util(root.right, distance+1, height+1, distance_map)


    @staticmethod
    def bottom_view(root ):
        """Prints bottom view from left to
        A node x is there in output if x is the bottommost node at its horizontal distance.
        If there are multiple bottom-most nodes for a horizontal distance from root, then
        print the later one in level traversal.
        *Algo:
        - Create a dictionary with key as horizontal distance and value as tuple of (height, node value)
        Perform a pre-order traversal of the tree. If the current node at a horizontal distance of height
         is the first we’ve seen, insert it in the map. Otherwise, compare the node with the existing
         one in map and if the height of the new node is greater, update in the Map.
        *Analysis:
        - Time Complexity = O(n)
        - Space Complexity = O(n)
        """
        distance_map = dict()
        TreeViews.__bottom_view_util(root, 0, 1, distance_map)

        for k in sorted([i for i in distance_map.keys()]):
            print((distance_map[k])[1],  end='  ')


if __name__ == '__main__':
    bt = BinaryTree.from_list( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15])
    bt.pprint()
    print("Different views of binary tree")
    print('     Left view - ', end='  ')
    TreeViews.left_view(bt.get_root(), 1, [0])
    print()
    print('     Right view - ', end='  ')
    TreeViews.right_view(bt.get_root(), 1, [0])
    print()
    print('     Top view - ', end='  ')
    TreeViews.top_view(bt.get_root())
    print()
    print('     Bottom view - ', end='  ')
    TreeViews.bottom_view(bt.get_root())
