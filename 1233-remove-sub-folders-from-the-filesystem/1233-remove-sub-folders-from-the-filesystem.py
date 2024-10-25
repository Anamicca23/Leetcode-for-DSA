from typing import List

class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        result = [folder[0]]
        
        for fld in folder[1:]:
            if not fld.startswith(result[-1] + '/'):
                result.append(fld)
                
        return result
