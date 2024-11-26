class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        teams=[]
        for row in grid:
            teams.append(row.count(1))
        win=max(teams)
        return teams.index(win)