import matplotlib.pyplot as plt
import numpy as np
from sklearn.tree import DecisionTreeClassifier
from tensorflow import keras
from keras.layers import Dense, Dropout, Embedding, LSTM, Bidirectional, SimpleRNN,L
from sklearn.model_selection import  GridSearchCV
from sklearn.metrics import precision_score
from sklearn.metrics import recall_score
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import LSTM
from sklearn.preprocessing import MinMaxScaler
from sklearn.metrics import mean_squared_error
def create_dataset(dataset, look_back=1):
    dataX, dataY = [], []
    for i in range(len(dataset)-look_back-1):
        a = dataset[i:(i+look_back), 0]
        dataX.append(a)
        dataY.append(dataset[i + look_back, 0])
    return np.array(dataX), np.array(dataY)
# Press the green button in the gutter to run the script.
if __name__ == '__main__':

    body_acc_x_train=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\train\Inertial Signals\body_acc_x_train.txt")
    body_acc_y_train=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\train\Inertial Signals\body_acc_y_train.txt")
    body_acc_z_train=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\train\Inertial Signals\body_acc_z_train.txt")
    body_gyro_x_train=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\train\Inertial Signals\body_gyro_x_train.txt")
    body_gyro_y_train=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\train\Inertial Signals\body_gyro_y_train.txt")
    body_gyro_z_train=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\train\Inertial Signals\body_gyro_z_train.txt")
    total_acc_x_train=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\train\Inertial Signals\total_acc_x_train.txt")
    total_acc_y_train=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\train\Inertial Signals\total_acc_y_train.txt")
    total_acc_z_train=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\train\Inertial Signals\total_acc_z_train.txt")
    body_acc_x_test=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\test\Inertial Signals\body_acc_x_test.txt")
    body_acc_y_test=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\test\Inertial Signals\body_acc_y_test.txt")
    body_acc_z_test=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\test\Inertial Signals\body_acc_z_test.txt")
    body_gyro_x_test=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\test\Inertial Signals\body_gyro_x_test.txt")
    body_gyro_y_test=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\test\Inertial Signals\body_gyro_y_test.txt")
    body_gyro_z_test=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\test\Inertial Signals\body_gyro_z_test.txt")
    total_acc_x_test=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\test\Inertial Signals\total_acc_x_test.txt")
    total_acc_y_test=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\test\Inertial Signals\total_acc_y_test.txt")
    total_acc_z_test=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\test\Inertial Signals\total_acc_z_test.txt")
    y_train=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\train\y_train.txt")
    y_test=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\test\y_test.txt")
    traintxt=np.loadtxt(r"E:\sources\UCI HAR Dataset\UCI HAR Dataset\train\subject_train.txt")
    x_train=np.dstack((body_acc_x_train,body_acc_y_train,body_acc_z_train,body_gyro_x_train,body_gyro_y_train,body_gyro_z_train,total_acc_x_train,total_acc_y_train,total_acc_z_train))
    x_test=np.dstack((body_acc_x_test,body_acc_y_test,body_acc_z_test,body_gyro_x_test,body_gyro_y_test,body_gyro_z_test,total_acc_x_test,total_acc_y_test,total_acc_z_test))

    traindatasets=[body_acc_x_train,body_acc_y_train,body_acc_z_train,body_gyro_x_train,body_gyro_y_train,body_gyro_z_train,total_acc_x_train,total_acc_y_train,total_acc_z_train]
    namedatasets=["body_acc_x_train","body_acc_y_train","body_acc_z_train","body_gyro_x_train","body_gyro_y_train","body_gyro_z_train","total_acc_x_train","total_acc_y_train","total_acc_z_train"]
    count=0
    for x in traindatasets:
        x=x[ : , 0:64]
        x=x[0:347 , : ]
    x = x.flatten()
    list_array = list(np.arange(1,len(x)+1))
    print(len(list_array))
    for x in traindatasets:
        for i in range(0,348):
            if y_train[i]==1:
                plt.plot(list_array[i*64:(i+1)*64], traindatasets[count][i*64:(i+1)*64],color = "r", label="walking")
            if y_train[i]==2:
                plt.plot(list_array[i*64:(i+1)*64], traindatasets[count][i*64:(i+1)*64],color = "b", label="walking downstairs")
            if y_train[i]==3:
                plt.plot(list_array[i*64:(i+1)*64], traindatasets[count][i*64:(i+1)*64],color = 'orange', label="walking upstairs")
            if y_train[i]==4:
                plt.plot(list_array[i*64:(i+1)*64], traindatasets[count][i*64:(i+1)*64],color = "k", label="sitting")
            if y_train[i]==5:
                plt.plot(list_array[i*64:(i+1)*64], traindatasets[count][i*64:(i+1)*64],color = "g", label="standing")
            if y_train[i]==6:
                plt.plot(list_array[i*64:(i+1)*64], traindatasets[count][i*64:(i+1)*64],color = "c", label="laying")

        plt.title(namedatasets[count])
        plt.xlabel("Timestamps")
        plt.ylabel("Body Data")
        plt.show()
        count+=1
    model = Sequential()
    model.add(SimpleRNN(20, input_shape=(128,9)))
    model.add(Dense(units=10, activation='relu'))
    model.add(Dense(units=6, activation='softmax'))
    model.compile(loss="categorical_crossentropy", optimizer='adam',metrics=["accuracy"])
    y_train_cat = keras.utils.to_categorical(y_train-1, num_classes=6)
    model.fit(x_train,y_train_cat,epochs=20)
    y_test_cat = keras.utils.to_categorical(y_test-1, num_classes=6)
    loss,accuracy = model.evaluate(x_test, y_test_cat)
    print(accuracy)
    # Make prediction on the test set
    pred = model.predict(x_test)
    # calculating precision and recall
    precision = precision_score(y_test, pred)
    recall = recall_score(y_test, pred)

    print('Precision: ', precision)
    print('Recall: ', recall)
    params={'batch_size':[100, 20, 50, 25, 32],
            'nb_epoch':[20, 10, 30, 40],
            'unit':[5,6, 10, 11, 12, 15],
            }
    gs=GridSearchCV(estimator=model, param_grid=params, cv=10)
    gs = gs.fit(x_train, y_train_cat)
    best_params=gs.best_params_
    accuracy=gs.best_score_
    model.predict(x_test)
    classifer_tree = DecisionTreeClassifier()
    y_predict = classifer_tree.fit(x_train,y_train).predict(x_test)
    scaler = MinMaxScaler(feature_range=(0, 1))
    dataset = scaler.fit_transform(x_test)
    caler = MinMaxScaler(feature_range=(0, 1))
    dataset = scaler.fit_transform(x_train)
    # split into train and test sets
    train_size = int(len(dataset) * 0.67)
    test_size = len(dataset) - train_size
    train, test = dataset[0:train_size, :], dataset[train_size:len(dataset), :]
    # reshape into X=t and Y=t+1
    look_back = 3
    trainX, trainY = create_dataset(train, look_back)
    testX, testY = create_dataset(test, look_back)
    # reshape input to be [samples, time steps, features]
    trainX = np.reshape(trainX, (trainX.shape[0], trainX.shape[1], 1))
    testX = np.reshape(testX, (testX.shape[0], testX.shape[1], 1))
    # create and fit the LSTM network
    batch_size = 1
    model = Sequential()
    model.add(LSTM(4, batch_input_shape=(batch_size, look_back, 1), stateful=True, return_sequences=True))
    model.add(LSTM(4, batch_input_shape=(batch_size, look_back, 1), stateful=True))
    model.add(Dense(1))
    model.compile(loss='mean_squared_error', optimizer='adam')
    for i in range(100):
        model.fit(trainX, trainY, epochs=1, batch_size=batch_size, verbose=2, shuffle=False)
        model.reset_states()
    # make predictions
    trainPredict = model.predict(trainX, batch_size=batch_size)
    model.reset_states()
    testPredict = model.predict(testX, batch_size=batch_size)
    # invert predictions
    trainPredict = scaler.inverse_transform(trainPredict)
    trainY = scaler.inverse_transform([trainY])
    testPredict = scaler.inverse_transform(testPredict)
    testY = scaler.inverse_transform([testY])
    # calculate root mean squared error
    trainScore = np.sqrt(mean_squared_error(trainY[0], trainPredict[:, 0]))
    print('Train Score: %.2f RMSE' % (trainScore))
    testScore = np.sqrt(mean_squared_error(testY[0], testPredict[:, 0]))
    print('Test Score: %.2f RMSE' % (testScore))
    # shift train predictions for plotting
    trainPredictPlot = np.empty_like(dataset)
    trainPredictPlot[:, :] = np.nan
    trainPredictPlot[look_back:len(trainPredict) + look_back, :] = trainPredict
    # shift test predictions for plotting
    testPredictPlot = np.empty_like(dataset)
    testPredictPlot[:, :] = np.nan
    testPredictPlot[len(trainPredict) + (look_back * 2) + 1:len(dataset) - 1, :] = testPredict
    # plot baseline and predictions
    plt.plot(scaler.inverse_transform(dataset))
    plt.plot(trainPredictPlot)
    plt.plot(testPredictPlot)
    plt.show()
    model = Sequential()
    model.add(Embedding(x_train, 128, input_length=len(list_array)))
    model.add(Bidirectional(LSTM(64)))
    model.add(Dropout(0.5))
    model.add(Dense(1, activation='sigmoid'))
    model.compile(loss='binary_crossentropy', optimizer='adam', metrics=['accuracy'])
    history = model.fit(x_train, y_train,
                        batch_size=20,
                        epochs=20,
                        validation_data=[x_test, y_test])
    print(history.history['loss'])
    print(history.history['accuracy'])
    from matplotlib import pyplot

    pyplot.plot(history.history['loss'])
    pyplot.plot(history.history['accuracy'])
    pyplot.title('model loss vs accuracy')
    pyplot.xlabel('epoch')
    pyplot.legend(['loss', 'accuracy'], loc='upper right')
    pyplot.show()
