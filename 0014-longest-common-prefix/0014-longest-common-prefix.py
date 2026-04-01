class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # result = ""

        # for i in range(len(strs[0])):
        #     char = strs[0][i]

        #     for word in strs : 
        #         if i >= len(word) or word[i] != char:
        #             return result
        #     result+= char
        
        # return result

        strs.sort()
        first = strs[0]
        last = strs[-1]
        i=0

        while i < len(first) and i< len(last) and first[i] == last[i] :
            i+=1
        return first[:i]    



                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   