# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        depth = []
        visited = []
        stack = [root]
        stackForDepth = [1]
        maxDepth = 0
        
        while stack:
            node = stack.pop()
            currentDepth = stackForDepth.pop()
            if maxDepth < currentDepth:
                maxDepth = currentDepth
            if node is None:
                return 0
            if node not in visited:
                level = []
                visited.append(node)
                if node.left is not None:
                    stack.append(node.left)
                    stackForDepth.append(currentDepth + 1)
                if node.right is not None:
                    stack.append(node.right)
                    stackForDepth.append(currentDepth + 1)
        print(len(depth))
        return maxDepth