import numpy as np

def hardlim(n):
    if n < 0:
        value = 0
    else:
        value = 1
    return value

#     a b c d e f g
P = [[1,1,1,1,1,1,0], #0
     [0,1,1,0,0,0,0], #1
     [1,1,0,1,1,0,1], #2
     [1,1,1,1,0,0,1], #3
     [0,1,1,0,0,1,1], #4
     [1,0,1,1,0,1,1], #5
     [1,0,1,1,1,1,1], #6
     [1,1,1,0,0,0,0], #7
     [1,1,1,1,1,1,1], #8
     [1,1,1,1,0,1,1]] #9

#Valores esperados
         #0,1,2,3,4,5,6,7,8,9
primos = [0,0,1,1,0,1,0,1,0,0]

e = np.ones(10)

#Pesos y polarizacón aleatoria
W = 2*np.random.rand(1,7) - 1
b = 2*np.random.rand(1) - 1

for epocas in range(25):
    for i in range(10):
        a = hardlim(np.dot(W,P[i])+b)   #Neurona 1
        e[i] = primos[i]-a
        W += np.dot(e[i],P[i]).T
        b += e[i]

print("Error: \n", e,'\n')
print("Pesos: \n", W,'\n')
print("Polarización: \n", b,'\n')


