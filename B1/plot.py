import pandas
import sys
from matplotlib import pyplot as plt

data =  pandas.read_csv(sys.argsv[1])

print(data.head)

print(data.n)
print(data.res)
mediana = data.res.median()

plt.plot(data.n, data.res)
plt.show()
plt.savefig(sys.argv[1] + ".png")
#etc