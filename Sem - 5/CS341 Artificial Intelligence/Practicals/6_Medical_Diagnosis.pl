symptom('Parth', 'High Temp').
symptom('Parth', 'Sneezing').
symptom('Parth', 'Sore Throat').

symptom('Manan', 'Itching').
symptom('Manan', 'Blisters').
symptom('Manan', 'Weakness').

symptom('Ayush', 'Yellow Eyes').
symptom('Ayush', 'Abdominal Pain').
symptom('Ayush', 'Vomitting').

symptom('a', 'Fever').
symptom('a', 'Weakness').
symptom('a', 'Sizziness').

symptom('b', 'Fever').
symptom('b', 'Sore Throat').
symptom('b', 'Joint Pain').

diagnose(X, 'Cold') :- symptom(X,'High Temp'), symptom(X, 'Sneezing'), symptom(X, 'Sore Throat').
diagnose(X, 'Chickenpox'):- symptom(X,'Itching'), symptom(X, 'Blisters'), symptom(X, 'Weakness').
diagnose(X, 'Jaundice') :- symptom(X, 'Yellow Eyes'), symptom(X, 'Abdominal Pain'), symptom(X, 'Vomitting').
diagnose(X, 'COVID-19') :- symptom(X, 'Fever'), symptom(X, 'Sore Throat'), symptom(X, 'Joint Pain').
diagnose(X, 'Malaria') :- symptom(X, 'Fever'), symptom(X, 'Weakness'), symptom(X, 'Sizziness').

