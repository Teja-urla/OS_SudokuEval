import matplotlib.pyplot as plt
from numpy import mean
# Plot1 - Time taken vs Number of threads:
# Here the y-axis will be time taken while the x-axis will be
# number of threads varying from 2 to 32 as 2 4 8 16 32.
# Fix the number of input points to be 6 ∗ 106
# (6 million).
x=[2,4,8,16,32,64]

plt.title(" Graph-2 comparision Pthreads vs OpenMP ")
plt.xlabel("Number of threads")
plt.ylabel("Time taken in µs")
#For  p_threads

# for 4:




y1=mean([2694,2379,2203,2257,2430])
y2=mean([1990,1826,3224,1680,1627])
y3=mean([2787,2735,2553,2731,1256])
y4=mean([2575,2778,1998,2075,1927])
y5=mean([2781,2871,2347,2670,2590])
y6=mean([4124,4265,2749,3759,3262])
y=[y1,y2,y3,y4,y5,y6]
plt.plot(x,y,label="p_thread",color="blue")
for xy in zip(x,y):
    plt.annotate('(%d, %ld)' %xy ,xy=xy)
plt.scatter(x,y,color="blue")

#for OMP

# y1=mean([1762,1060,1333,1675,1014])
# y2=mean([3421,3097,2975,3252,4025])
# y3=mean([4916,3077,4321,3394,3124])
# y4=mean([2548,2436,2041,2525,2774])
# y5=mean([3307,2828,3194,3140,2630])
# y6=mean([3358,3141,3228,3430,4535])
# y=[y1,y2,y3,y4,y5,y6]
# plt.plot(x,y,label="openmp",color="red")
# for xy in zip(x,y):
#     plt.annotate('(%d, %ld)' %xy ,xy=xy)
# plt.scatter(x,y,color="red")


plt.tight_layout()
plt.legend(loc="upper right")
plt.grid()
plt.savefig('G2.png',dpi=400)
plt.show()

#mention 6 million number in graph,legend,labels
