
# coding: utf-8

# In[1]:


import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
get_ipython().run_line_magic('matplotlib', 'inline`')


# In[4]:


df=pd.read_csv('/media/debanjan/0648C71248C70003/Users/Debanjan/Desktop/Machine Learning A-Z Template Folder/Part 2 - Regression/Section 4 - Simple Linear Regression/Salary_Data.csv')
df.head()


# In[102]:


x = np.matrix(df.YearsExperience)
y = np.matrix(df.Salary)
print(x,y)


# In[103]:


x = np.append(np.matrix(np.ones(x.shape[1])), x, axis=0)


# In[117]:


beta = np.matrix(np.zeros(x.shape[0]))
#print(beta)
error = (y_hat-y)
e_bar = np.fabs(error).mean()
for i in range(1000000):
    e_bar = np.fabs(error).mean()
    delf=error@x.transpose()
    beta = beta - 0.00249*2*delf/x.shape[1]
    y_hat = beta@x
    error = (y_hat-y)
    if(np.fabs(error).mean() == e_bar):
        break
    
print(beta)
plt.scatter(np.array(x[1]),np.array(y),c='b');
z=np.linspace(0,10,100)
y_pred=beta[0,0]+beta[0,1]*z
plt.plot(z,y_pred,c='r');


# In[100]:


from sklearn.linear_model import LinearRegression
lr = LinearRegression()
m=df.iloc[:,0]
n=df.iloc[:,-1]
lr.fit(np.array(m).reshape(-1,1),np.array(n).reshape(-1,1))
print([lr.intercept_,lr.coef_])

