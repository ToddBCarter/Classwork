import numpy as np
import pandas as pd

data = pd.read_csv('./world_energy.csv')

parsed = pd.DataFrame()

parsed['Year'] = data['year']
parsed['Country'] = data['country']
parsed['Population'] = data['population']
parsed['GDP'] = data['gdp']
parsed['Fossils'] = data['fossil_electricity']
parsed['Renewables'] = data['renewables_electricity']
parsed = parsed.dropna()

parsed.to_csv('world_enenrgy_preprocessed.csv', index=False)
