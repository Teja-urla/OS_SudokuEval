import matplotlib.pyplot as plt
from numpy import mean
# Plot1 - Time taken vs Number of threads:
# Here the y-axis will be time taken while the x-axis will be
# number of threads varying from 2 to 32 as 2 4 8 16 32.
# Fix the number of input points to be 6 ∗ 106
# (6 million).
x=[9,16,25,36,49,64,81,100]
plt.title("Graph-1 Pthreads vs OpenMP ")
plt.xlabel("Size of sudoku (nxn)")
plt.ylabel("Time taken in µs")
#For  p_threads
y1=mean([1146,1361,1322,1255,1064]) #9
y2=mean([1665,1737,1711,1598,1558]) #16
y3=mean([2350,1916,1856,2091,2190]) #25
y4=mean([6107,6481,5868,3760,3676]) #36
y5=mean([8420,9253,6724,6416,9028]) #49
y6=mean([13946,15138,23925,11376,23996]) #64
y7=mean([22772,22064,32586,23220,27767]) #81
y8=mean([40740,39881,48751,39919,46497]) #100
y=[y1,y2,y3,y4,y5,y6,y7,y8]
plt.plot(x,y,label="p_thread",color="blue")
for xy in zip(x,y):
    plt.annotate('(%d, %ld)' %xy ,xy=xy)
plt.scatter(x,y,color="blue")

#for OMP


y1=mean([1976,1585,1717,1838,1521])
y2=mean([1889,1696,1668,1692,1817])
y3=mean([2483,2748,2156,2617,2998])
y4=mean([5245,3882,6162,6764,6551])
y5=mean([8557,9081,6711,9271,9585])
y6=mean([11616,12335,15229,23110,15967])
y7=mean([21968,23952,22564,32675]) 
y8=mean([41470,39823,47719,40273,48204])
y=[y1,y2,y3,y4,y5,y6,y7,y8]
plt.plot(x,y,label="openmp",color="red")
for xy in zip(x,y):
    plt.annotate('(%d, %ld)' %xy ,xy=xy)
plt.scatter(x,y,color="red")


plt.tight_layout()
plt.legend(loc="upper right")
plt.grid()
plt.savefig('G1.png',dpi=400)
plt.show()
#mention 6 million number in graph,legend,labels
