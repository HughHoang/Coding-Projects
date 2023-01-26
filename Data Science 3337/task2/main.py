# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
from openpyxl import Workbook
import pandas as pd
import numpy as np
import math
from scipy import stats
from matplotlib import pyplot as plt
from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn import tree


def plot_colors(student_id):
    color1 = "#" + student_id[1:]
    color2 = "#" + str(hex(int("FFFFFF", 16) - int(student_id[1:], 16)))[2:]
    return color1, color2


psid = "1833106"
color1, color2 = plot_colors(psid)


def newfeature(dataset):
    dataset['fnew'] = dataset.iloc[:, 0].pow(2) + dataset.iloc[:, 0].pow(2)
    dataset['fnew'] = dataset['fnew'] ** (1 / 2)
    return dataset

def myfunc(x):
    return slope * x + intercept

def pipeline(dataset, sampling, numsamples, setnumber):
    if sampling=='stf':
        regsample(numsamples)
    else:
        regsample(numsamples)
    return dataset

def selection(dataset):
    dataset4 = dataset3
    dataset4 = dataset4.filter(['Feature 1', 'Feature 4'], axis=1)
    return dataset


def regsample(q):
    chosen_idx = np.random.choice(8400, q, replace=False)
    dataset2 = df.iloc[chosen_idx]
    return dataset2

def strasample(q):
    chosen_idx = np.random.choice(8400, q, replace=False)
    dataset2 = df.iloc[chosen_idx]
    return dataset2


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    df = pd.read_excel(
        r'E:\sources\ExcelTask2.xlsx')  # place "r" before the path string to address special character, such as '\'. Don't forget to put the file name at the end of the path + '.xlsx'
    rows = len(df.axes[0])
    col = df.axes[1]
    # PROBLEM 2.1
    class0 = df.loc[df['Label'] == 0]
    class1 = df.loc[df['Label'] == 1]
    # print (len(class0))
    # print (len(class1))
    q = 1000
    # PROBLEM 2.2
    dataset2 = regsample(q)
    df20 = dataset2.loc[dataset2['Label'] == 0]
    df21 = dataset2.loc[dataset2['Label'] == 1]
    # print (len(df20))
    # print (len(df21))
    # PROBLEM 2.3
    dataset3 = df
    dataset3 = dataset3.groupby('Label', group_keys=False).apply(lambda x: x.sample(frac=0.11904761904))
    df30 = dataset3.loc[dataset3['Label'] == 0]
    df31 = dataset3.loc[dataset3['Label'] == 1]
    # print (len(df30))
    # print (len(df31))
    # PROBLEM 2.4
    covMatrix = pd.DataFrame.cov(dataset3)
    # print (covMatrix)
    dataset4 = dataset3
    dataset4 = dataset4.filter(['Feature 1', 'Feature 4'], axis=1)
    # PROBLEM 2.5
    slope, intercept, r, p, std_err = stats.linregress(dataset4['Feature 1'], dataset4['Feature 4'])
    mymodel = list(map(myfunc, dataset4['Feature 1']))
    plt.scatter(dataset4['Feature 1'], dataset4['Feature 4'], color=color2, alpha=0.3)
    plt.plot(dataset4['Feature 1'], mymodel)
    plt.show()

    # PROBLEM 2.6
    h0dataset=dataset3.loc[dataset3['Label'] == 0]
    h1dataset=dataset3.loc[dataset3['Label'] == 1]
    h1=h0dataset['Feature 1']
    h2=h0dataset['Feature 4']
    h3=h1dataset['Feature 1']
    h4=h1dataset['Feature 4']

    plt.xlabel("Class0 Feature 1")
    plt.ylabel("Frequency")
    plt.hist(h1, color=color2)
    plt.show()

    plt.xlabel("Class0 Feature 4")
    plt.ylabel("Frequency")
    plt.hist(h2, color=color2)
    plt.show()

    plt.xlabel("Class1 Feature 1")
    plt.ylabel("Frequency")
    plt.hist(h3, color=color2)
    plt.show()

    plt.xlabel("Class1 Feature 4")
    plt.ylabel("Frequency")
    plt.hist(h4, color=color2)
    plt.show()

# Problem 2.7
    training_set = dataset3
    training_set1 = training_set.filter(['Feature 1', 'Feature 4', 'Label'], axis=1)
    training_set = training_set1.sample(n=700)
    datasetlabel1 = dataset3.filter(['Feature 1', 'Feature 4', 'Label'], axis=1)
    testing_set1 = pd.concat([datasetlabel1, training_set, training_set]).drop_duplicates(keep=False)
    training_setlabel = training_set['Label']
    training_set = training_set.filter(['Feature 1', 'Feature 4'], axis=1)
    testing_setlabel = testing_set1['Label']
    testing_set = testing_set1.filter(['Feature 1', 'Feature 4'], axis=1)
    # Problem 2.8
    tree = DecisionTreeClassifier(max_depth=3)
    tree.fit(training_set, training_setlabel)
    tree_dot = plot_tree(tree)
    plt.show()
    #accuracy_score(training_set, training_setlabel)
    # Problem 2.9
    c_training_set = newfeature(training_set1)
    c_testing_set = newfeature(testing_set1)
    # Problem 2.10
    c_training_set0 = c_training_set.loc[c_training_set['Label'] == 0]
    c_training_set1 = c_training_set.loc[c_training_set['Label'] == 1]
    plt.xlabel("c_training_set0")
    plt.ylabel("Frequency")
    plt.hist(c_training_set0['fnew'], color=color2)
    plt.show()

    plt.xlabel("c_training_set1")
    plt.ylabel("Frequency")
    plt.hist(c_training_set1['fnew'], color=color2)
    plt.show()
    # Problem 2.11
    tree = DecisionTreeClassifier(max_depth=3)
    tree.fit(c_testing_set, testing_setlabel)
    tree_dot = plot_tree(tree)
    plt.show()
    #accuracy_score(c_testing_set, testing_setlabel)
    # Problem 2.12
    pipeline(df, 'stf',  500, 300)
    pipeline(df,  'rgl', 100,70)
    pipeline(df, 'stf', 1500,1000)
