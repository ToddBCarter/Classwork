import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Load dataset
df = pd.read_csv("crocodile_dataset.csv")

new_frame = pd.DataFrame()

# Convert date to datetime and extract year
df["Date of Observation"] = pd.to_datetime(df["Date of Observation"], errors="coerce")
new_frame["Year"] = df["Date of Observation"].dt.year

# Normalize conservation status text
df["Conservation Status"] = df["Conservation Status"].str.strip().str.title()

# --- NUMERIC STATUS MAPPING WITHOUT 'NEAR THREATENED' ---
status_map = {
    "Least Concern": 0,
    "Vulnerable": 1,
    "Endangered": 2,
    "Critically Endangered": 3
}

new_frame["StatusValue"] = df["Conservation Status"].map(status_map)
new_frame["name"] = df["Scientific Name"]

croc_dict = {}

for croc in new_frame["name"]:
    if(croc not in croc_dict.keys()):
        croc_dict[croc] = [0, 0, 0, 0]

for i, row in new_frame.iterrows():
    if pd.isna(row["StatusValue"]):
        continue  # skip rows with unknown status
    cur_row = croc_dict[row["name"]]
    cur_row[int(row["StatusValue"])] += 1

for key in croc_dict:
    print(key, ": ", croc_dict[key])

data = np.array(list(croc_dict.values()))
species = list(croc_dict.keys())
statuses = ["LC", "V", "EN", "CR"]

plt.figure(figsize=(8, len(species)*0.5))
plt.imshow(data, aspect="auto")
plt.colorbar(label="Count")
plt.yticks(np.arange(len(species)), species)
plt.xticks(np.arange(4), statuses)
plt.title("Conservation Status Position per Species")
plt.show()

plt.savefig("plot.png")
