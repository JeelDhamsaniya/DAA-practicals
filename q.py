import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import make_interp_spline
import matplotlib
matplotlib.use('TkAgg')

def plot_case(filename, title):
    df = pd.read_csv(filename)
    X = df['InputSize'].to_numpy()

    plt.figure(figsize=(12, 8))
    styles = {
        'Selection1': 'r--',
        'Selection2': 'r:',
        'Bubble1': 'g-.',
        'Bubble2': 'g-',
        'Insertion1': 'b-',
        'Insertion2': 'b--'
    }

    def smooth(y, X):
        valid = ~(np.isnan(y) | np.isinf(y))
        if valid.sum() < 4:
            return X[valid], y[valid]
        x_clean = X[valid]
        y_clean = y[valid]
        xnew = np.linspace(x_clean.min(), x_clean.max(), 500)
        spline = make_interp_spline(x_clean, y_clean, k=3)
        return xnew, spline(xnew)

    for algo in styles:
        y = df[algo].to_numpy()
        xnew, ynew = smooth(y, X)
        plt.plot(xnew, ynew, styles[algo], label=algo)

    plt.title(f'{title} - Input Size vs Time', fontsize=16)
    plt.xlabel('Input Size')
    plt.ylabel('Time (microseconds)')
    plt.grid(True)
    plt.legend()
    plt.tight_layout()

plot_case('ascending.csv', 'Ascending Case (Best)')
plot_case('descending.csv', 'Descending Case (Worst)')
plot_case('random.csv', 'Random Case (Average)')
plt.show(block=False)
input("Press Enter to close all plots...")

