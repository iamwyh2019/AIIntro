import random
import math

def calc(x,y,z,pts):
    ans, gx, gy, gz = 0, 0, 0, 0
    for u, v, w in pts:
        dx, dy, dz = x-u, y-v, z-w
        dis = math.sqrt(dx**2 + dy**2 + dz**2)
        if dis > ans:
            ans = dis
            gx = dx / dis
            gy = dy / dis
            gz = dz / dis
    return ans, gx, gy, gz

def main():
    while True:
        n = int(input())
        if n == 0:
            break
        pts = [0] * n
        for i in range(n):
            x,y,z = map(float, input().split())
            pts[i] = (x,y,z)
        
        gans = float("inf")

        for i in range(10):
            nx = random.random() * 100
            ny = random.random() * 100
            nz = random.random() * 100
            T = 100 * math.sqrt(3)

            while T > 1e-8:
                ans, gx, gy, gz = calc(nx,ny,nz,pts)
                gans = min(gans, ans)
                nx -= gx * T
                ny -= gy * T
                nz -= gz * T
                T *= 0.98
        
        print("{:.5f}".format(gans))

if __name__ == "__main__":
    main()
