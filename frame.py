# Abrir un archivo de audio .wav
import numpy as np
import matplotlib.pyplot as plt
import soundfile as sf

archivo = 'frame.wav'
data, samplerate = sf.read(archivo)
t=np.arange(0,len(data))/samplerate
corr=np.correlate(data, data, 'full')
corr=corr[int(corr.size/2):]
corr=corr/np.max(corr)


fig, axs = plt.subplots(2)
fig.suptitle('Señal sonora')
axs[0].plot(t, data)
axs[1].plot(t, corr)
axs[0].grid()
axs[1].grid()
plt.show()