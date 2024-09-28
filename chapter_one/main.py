import pandas as pd 
import matplotlib.pyplot as plt 

def main() -> None : 
    BASE_URL: str = "results/timeconsumption.csv" 
    data = pd.read_csv(BASE_URL)    
    plt.figure(figsize=(10, 15)) 
    plt.plot(data["VectorSize"], data["TimeForSelection"], '--g')
    plt.plot(data["VectorSize"], data["TimeForSorting"], "-r")
    plt.show() 

if __name__ == "__main__" :
    main() 
    
