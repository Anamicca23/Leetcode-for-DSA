class Solution:
    def robotSim(self,commands,obstacles):
        x,y,d=0,0,0
        direction=[(0,1),(1,0),(0,-1),(-1,0)]
        max_distance=0
        obstacles=set(map(tuple,obstacles))
        
        for cmd in commands:
            if cmd==-1:
                d=(d+1)%4
            elif cmd==-2:
                d=(d-1)%4
            else:
                for _ in range(cmd):
                    nx,ny=x+direction[d][0],y+direction[d][1]
                    if (nx,ny) in obstacles:
                        break
                    x,y=nx,ny
                    max_distance=max(max_distance,x*x+y*y)
        
        return max_distance