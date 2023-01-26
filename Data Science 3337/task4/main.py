import pandas as pd
import numpy as np
import seaborn as sns
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
from sklearn import metrics
import scipy.stats as stats
from sklearn.cluster import DBSCAN
from sklearn.neighbors import NearestNeighbors
from matplotlib import pyplot as plt
from scipy.spatial.distance import cdist

def purity_score(df,y_true, y_pred, labels,outliers):
    if outliers:
        outliers = df[labels == -1]
        contingency_matrix = metrics.cluster.contingency_matrix(y_true, y_pred)
        return np.sum(np.amax(contingency_matrix, axis=0)) / np.sum(contingency_matrix), outliers.shape[0]/df.shape[0]
    else:
        contingency_matrix = metrics.cluster.contingency_matrix(y_true, y_pred)
        return np.sum(np.amax(contingency_matrix, axis=0)) / np.sum(contingency_matrix)

def kmeansB(df,num_k):
    kmeans = KMeans(n_clusters=num_k, init='k-means++', random_state=0).fit(df)
    sns.scatterplot(data=df, x=df[0], y=df[1], hue=kmeans.labels_)
    plt.show()

    tp=df[0]
    fp=df[1]
    X=np.vstack((tp,fp)).T
    y=df[2]
    model = KMeans(n_clusters = num_k,random_state=42)
    df_kmeans=model.fit(X)
    df_purity=purity_score(df,y, df_kmeans.labels_, None ,False)
    print("Purity: ", df_purity)

def kmeansC(df,num_k):
    X=np.vstack((df[0],df[1],df[2],df[3],df[4],df[5],df[6],df[7],df[8])).T
    y=df[9]
    model = KMeans(n_clusters = num_k,random_state=42)
    df_kmeans=model.fit(X)
    df_purity=purity_score(df,y, df_kmeans.labels_, None,False)

    centers = np.array(df_kmeans.cluster_centers_)
    print("Centroids: ", centers)
    data_with_clusters = df.copy()
    data_with_clusters['Clusters'] = df_kmeans.labels_

    plt.boxplot(df.loc[df_kmeans.labels_==0],0,'')
    plt.title("Cluster 1")
    plt.show()
    plt.boxplot(df.loc[df_kmeans.labels_==1],0,'')
    plt.title("Cluster 2")
    plt.show()
    plt.boxplot(df.loc[df_kmeans.labels_==2],0,'')
    plt.title("Cluster 3")
    plt.show()

    print("Purity: ", df_purity)
    return df_purity


def remove_outliers(df):
    Q1=df.quantile(0.25)
    Q3=df.quantile(0.75)
    IQR=Q3-Q1
    df_final=df[~((df<(Q1-1.5*IQR)) | (df>(Q3+1.5*IQR)))]
    return df_final

def dbscanD(df):
    x=np.vstack((df[0],df[1],df[2],df[3],df[4],df[5],df[6],df[7],df[8])).T
    y=df[9]
    dbscan = DBSCAN(eps=36, min_samples=3).fit(x)
    labels = dbscan.labels_
    plt.scatter(x[:, 0], x[:,1], c = labels, cmap= "plasma") # plotting the clusters
    plt.show()
    df_purity=purity_score(df,y, dbscan.labels_,labels,True)
    print(df_purity)

def dbscantest(df,dim):
    minPts=2*dim
    neighbors = NearestNeighbors(n_neighbors=minPts)
    neighbors_fit = neighbors.fit(df)
    distances, indices = neighbors_fit.kneighbors(df)
    distances = np.sort(distances, axis=0)
    distances = distances[:,1]
    print(minPts)
    plt.plot(distances)
    plt.show()

def dbscanE(df,minpoint,lowep,highep):
    purity = 0
    ep=0
    minPts=0
    for i in range(int(minpoint-minpoint/2),int(minpoint+minpoint/2)):
        for j in range(lowep,highep):
            tp=df[0]
            fp=df[1]
            x=np.vstack((tp,fp)).T
            y=df[2]
            dbscan = DBSCAN(eps=j, min_samples=i).fit(x)
            labels = dbscan.labels_
            df_purity=purity_score(df,y, dbscan.labels_,labels,True)
            #print((len(set(labels))),df_purity[0],df_purity[1])
            if((len(set(labels)) <=15) and (len(set(labels)) >=2) and (df_purity[1] < 0.1) and (df_purity[1] > purity)):
                ep=j
                minPts=i
                purity = df_purity[0]
            #print(purity)
    print ("Epsilon: ",ep,"MinPts: ",minPts,"Purity: ", purity)
    dbscan = DBSCAN(eps=ep, min_samples=minPts).fit(x)
    labels = dbscan.labels_
    plt.scatter(x[:, 0], x[:,1], c = labels, cmap= "plasma") # plotting the clusters
    plt.show()

def dbscanExtra(df,minpoint,lowep,highep):
    purity = 0
    ep=0
    minPts=0
    for i in range(int(minpoint-minpoint/2),int(minpoint+minpoint/2)):
        for j in range(lowep,highep):
            x=np.vstack((df[0],df[1],df[2],df[3],df[4],df[5],df[6],df[7],df[8])).T
            y=df[9]
            dbscan = DBSCAN(eps=j, min_samples=i).fit(x)
            labels = dbscan.labels_
            df_purity=purity_score(df,y, dbscan.labels_,labels,True)
            #print((len(set(labels))),df_purity[0],df_purity[1])
            if((len(set(labels)) <=15) and (len(set(labels)) >=2) and (df_purity[1] < 0.1) and (df_purity[1] > purity)):
                ep=j
                minPts=i
                purity = df_purity[0]
            #print(purity)
    print ("Epsilon: ",ep,"MinPts: ",minPts,"Purity: ", purity)
    dbscan = DBSCAN(eps=ep, min_samples=minPts).fit(x)
    labels = dbscan.labels_
    plt.scatter(x[:, 0], x[:,1], c = labels, cmap= "plasma") # plotting the clusters
    plt.show()

if __name__ == '__main__':
    int_df = pd.DataFrame((pd.read_csv("http://www2.cs.uh.edu/~ceick/UDM/DataSets/complex9_gn8.txt", header = None)))
    shuttle = pd.DataFrame((pd.read_csv("E:\sources\Shuttle22.csv", header = None)))
    zshut=shuttle.apply(stats.zscore)

    shuttlenoout=shuttle
    zshutnoout=shuttlenoout.apply(stats.zscore)
    zshutnoout=remove_outliers(zshutnoout)

    #b
    #kmeansB(int_df,9)
    #kmeansB(int_df,13)
    #plt. scatter(int_df[0], int_df[1], c=int_df[2])
    #plt.title("Natural Clusters")
    #plt.show()

    #c
    #zshutnoout.boxplot()
    #plt.title("Whole Dataset")
    #plt.show()
    #kmeansC(zshut,3)

    #d
    #dbscanD(zshut)

    #e
    #dbscantest(int_df,2)
    #dbscanE(int_df,4,7,11)

    #e
    #dbscantest(shuttle,2)
    dbscanExtra(shuttle,4,10,80)