import pandas as pd
import numpy as np
from tensorflow import keras
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

# Load data
df = /* TODO: Load CSV dataset (rssi_dataset.csv) */
X = df[['RSSI']].values
y = df['Distance'].values

# Normalize RSSI
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

rssi_mean = scaler.mean_[0]
rssi_std = np.sqrt(scaler.var_[0])

# Build and train model
model = keras.Sequential([
    keras.layers.Dense(8, activation='relu', input_shape=(1,)),
    keras.layers.Dense(8, activation='relu'),
    keras.layers.Dense(1)
])
model.compile(optimizer='adam', loss='mse')
/* TODO: Train model (use validation_split, epochs) */

# Save model and scaler
/* TODO: Save model to .h5 */
/* TODO: Save mean and std */
