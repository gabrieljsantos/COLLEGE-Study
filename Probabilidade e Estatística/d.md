# Fórmulas Essenciais para Variáveis Discretas Conjuntas

---

## 1️⃣ Esperança (Média) de uma variável discreta

Para uma variável discreta \(X\) com valores \(x_i\) e probabilidades \(P(X=x_i)\):

\[
E(X) = \sum_i x_i \cdot P(X=x_i)
\]

- Para uma variável derivada \(Z = aX + bY\):

\[
E(Z) = E(aX + bY) = a \cdot E(X) + b \cdot E(Y)
\]

---

## 2️⃣ Variância de uma variável discreta

\[
\text{Var}(X) = E[(X - E(X))^2] = \sum_i (x_i - E(X))^2 \cdot P(X=x_i)
\]

- Para uma combinação linear \(Z = aX + bY\):

\[
\text{Var}(aX + bY) = a^2 \cdot \text{Var}(X) + b^2 \cdot \text{Var}(Y) + 2ab \cdot \text{Cov}(X,Y)
\]

---

## 3️⃣ Covariância

Para duas variáveis X e Y com distribuição conjunta \(P(X=x_i, Y=y_j) = f_{ij}\):

\[
\text{Cov}(X,Y) = E[(X - E(X))(Y - E(Y))] = \sum_i \sum_j (x_i - E(X))(y_j - E(Y)) f_{ij}
\]

- Covariância positiva → X e Y tendem a aumentar juntos  
- Covariância negativa → quando X aumenta, Y tende a diminuir  

---

## 4️⃣ Coeficiente de correlação

\[
\rho_{X,Y} = \frac{\text{Cov}(X,Y)}{\sigma_X \cdot \sigma_Y}
\]

- Onde \(\sigma_X = \sqrt{\text{Var}(X)}, \quad \sigma_Y = \sqrt{\text{Var}(Y)}\)  
- \(-1 \leq \rho \leq 1\)

---

## 5️⃣ Função de probabilidade de variável derivada

Para \(Z = g(X,Y)\) (ex.: \(Z = X+Y\) ou \(Z = X \cdot Y\)):

\[
P(Z = z) = \sum_{(i,j) \text{ tal que } g(X_i, Y_j) = z} f_{ij}
\]

- Cada valor \(z\) recebe a **soma das probabilidades das combinações (X_i, Y_j) que produzem z**.

---

## 6️⃣ Esperança de variável derivada

\[
E(Z) = \sum_z z \cdot P(Z=z)
\]

- Para X+Y: \(E(X+Y) = \sum_i \sum_j (x_i + y_j) \cdot f_{ij}\)  
- Para X·Y: \(E(X \cdot Y) = \sum_i \sum_j (x_i \cdot y_j) \cdot f_{ij}\)  

---

## 7️⃣ Linearização de uma tabela conjunta

- Cada célula da tabela conjunta vira uma linha:  

| X | Y | P(X,Y) |  
|---|---|--------|  
| x1| y1| f11    |  
| x1| y2| f12    |  
| ...|...| ...   |  

- Facilita cálculo de:  
  - Covariância  
  - Esperança de X+Y ou X·Y  
  - Função de probabilidade de variáveis derivadas  

---

## 8️⃣ Resumo de cálculos importantes

- **Média de combinação linear:** \(E(aX + bY) = aE(X) + bE(Y)\)  
- **Variância de combinação linear:** \(\text{Var}(aX + bY) = a^2 \text{Var}(X) + b^2 \text{Var}(Y) + 2ab \text{Cov}(X,Y)\)  
- **Covariância:** \(\text{Cov}(X,Y) = E(XY) - E(X)E(Y)\)  
- **Função de probabilidade de variável derivada:** \(P(Z=z) = \sum f_{ij}\) onde Z = g(X_i,Y_j) = z  
- **Esperança de variável derivada:** \(E(Z) = \sum z \cdot P(Z=z)\)  

---

Essas fórmulas permitem resolver todos os exercícios:

1. Esperança e variância de \(Z = 2X + Y\)  
2. Esperança linear \(E(2X - 3Y)\), Cov(X,Y), Var(5X - 3Y)  
3. Correlação \(\rho_{X,Y}\) a partir de Cov(X,Y) e variâncias  
4. Cov(X,Y) a partir de tabela conjunta  
5. Função de probabilidade e esperança de \(X+Y\) e \(X\cdot Y\)
