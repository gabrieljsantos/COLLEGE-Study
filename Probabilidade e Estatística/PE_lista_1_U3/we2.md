
de uma popula n ormal X com variancia 121 retiramos uma amostra
de 25 observações, obtendo x medio = 45 . ao nivek de 2%, 
fazer um ic para v erdadeira media da população

calcular o desvio padrão da amostra
desvio padrao amostra = raiz quadrada da variancia amostra
desvio padrao amostra = raiz quadrada de 121 = 11


a formula de IC:

$$IC =\bar{x} \pm Z_{\alpha/2} \cdot \frac{\sigma}{\sqrt{n}}$$ 
                  

$$\alpha/2 = 0.02/2 = 0.01$$
$$Z_{\alpha/2} = z_{0.01} = 2.33$$
significancia de 2%, logo o nivel de conficancia é de 98% ou seja, 0.98
confiança:
$$c = 1 - \alpha = 1 - 0.02 = 0.98$$
$$Z_{\alpha/2} = z_{0.01} = 2.33$$
$$\bar{x} = 45$$
$$\sigma = \sqrt{121} = 11$$

dessa forma o IC:
$$IC = 45 \pm 2.33 \cdot \frac{11}{\sqrt{25}}$$
resolvendo:
$$IC = 45 \pm 2.33 \cdot \frac{11}{5}$$
$$IC = 45 \pm 2.33 \cdot 2.2$$
$$IC = 45 \pm 5.126$$
$$IC = (39.874, 50.126)$$



2- Uma loja tem os valores de suas vendas diárias dis-tribuídos normalmente com desvio padrão de R\$530,00. O gerente da loja, quando inquerido pelo dono, afirmou vender em média R\$34.720, 00. Posteriormente levantou-se uma amostra das vendas de determinado dia, obtendo-se os valores em reais (R\$):
tabela:
|33840, 00| 32960, 00| 41811, 00| 35080, 00| 35060, 00|
|-|-|-|-|-|
|32947,00| 32120,00| 32740,00| 33580,00| 33002,00

a) Construir um IC para a venda média diária ao nível de 5%.
$$desvio padrão = 530$$

> siginifcancia de 5%, logo o nivel de confiança é de 95% ou seja, 0.95
> nem precisava fazer a conta, pois significancia de 5% a direita é igual a confiança de 95% a esquerda.

$$c = 1 - \alpha = 1 - 0.05 = 0.95$$

$$Z_{\alpha/2} = z_{0.025} = 1.96$$


> o intervalo de IC é:

$$\bar{x} = \frac{33840 + 32960 + 41811 + 35080 + 35060 + 32947 + 32120 + 32740 + 33580 + 33002}{10}$$
$$\bar{x} = \frac{337640}{10}$$
$$\bar{x} = 33764$$
$$\sigma = 530$$
$$IC = \bar{x} \pm Z_{\alpha/2} \cdot \frac{\sigma}{\sqrt{n}}$$
$$IC = 33764 \pm 1.96 \cdot \frac{530}{\sqrt{10}}$$
$$IC = 33764 \pm 1.96 \cdot \frac{530}{3.162}$$
$$IC = 33764 \pm 1.96 \cdot 167.57$$
$$IC = 33764 \pm 328.63$$
$$IC = (33435.37, 34092.63)$$

b) Construir um IC para a venda média diária ao nível de 1%.

> siginifcancia de 1%, logo o nivel de confiança é de 99% ou seja, 0.99 

$$c = 1 - \alpha = 1 - 0.01 = 0.99$$ 

$$Z_{\alpha/2} = z_{0.005} = 2.58$$


substituindo os valores na formula de IC:

$$\bar{x} = \frac{33840 + 32960 + 41811 + 35080 + 35060 + 32947 + 32120 + 32740 + 33580 + 33002}{10}$$
$$\bar{x} = \frac{337640}{10}$$
$$\bar{x} = 33764$$

$$\sigma = 530$$

$$IC = \bar{x} \pm Z_{\alpha/2} \cdot \frac{\sigma}{\sqrt{n}}$$
$$IC = 33764 \pm 1.96 \cdot \frac{530}{\sqrt{10}}$$
$$IC = 33764 \pm 1.96 \cdot \frac{530}{3.162}$$
$$IC = 33764 \pm 1.96 \cdot 167.57$$
$$IC = 33764 \pm 328.63$$
$$IC = (33435.37, 34092.63)$$


c) Em qual dos dois níveis de significância podemos afirmar que o gerente se baseia para responder à indagação?
> dessa forma, podemos afirmar que o gerente se baseia para responder à indagação no nível de significância de 5%, pois o valor de R\$34.720,00 está dentro do intervalo de confiança construído para esse nível de significância, enquanto que para o nível de significância de 1% o valor não está dentro do intervalo de confiança.



4- Querendo estimar a proporção de defeitos de uma certa produção, examinou-se uma amostra de 100 itens, encontrando-se 30 defeituosos. Determinar o IC para a proporção p da população ao nível de 5%.

$n = 100$
$X = 30$
$\alpha = 0.05$

$IC = \hat{p} \pm Z_{\alpha/2} \cdot \sqrt{\frac{\hat{p}(1-\hat{p})}{n}}$
> usa-se essa forma como p, pois a proporção da amostra é a melhor estimativa para a proporção da população, e o desvio padrão é calculado com base na proporção da amostra.

> essa formla com p, sem desvio padão, é usada quando não tem desvio padrão conhecido, e a proporção da amostra é a melhor estimativa para a proporção da população.

valor de p:
$\hat{p} = \frac{X}{n} = \frac{30}{100} = 0.3$


$IC = 0.3 \pm Z_{0.025} \cdot \sqrt{\frac{0.3(1-0.3)}{100}}$
encontra o Z e ja foi.


7- Lança-se uma moeda 100 vezes e observa-se que ocorrem 40 caras. Baseado nesse resultado, podemos afirmar, ao nível de 5%, que a moeda não é honesta?

> entra diretamente 5% pois é nivel de significancia, e o nivel de confiança é de 95% ou seja, 0.95

$\alpha = 0.05$
$c = 1 - \alpha = 1 - 0.05 = 0.95$

$Z_{\alpha/2} = z_{0.025} = 1.96$

> como não temos desvio padrão conhecido, usamos a proporção da amostra como melhor estimativa para a proporção da população, e o desvio padrão é calculado com base na proporção da amostra.

$p = \frac{40}{100} = 0.4$

$IC = \hat{p} \pm Z_{\alpha/2} \cdot \sqrt{\frac{\hat{p}(1-\hat{p})}{n}}$

substituindo os valores:

$$IC = 0.4 \pm 1.96 \cdot \sqrt{\frac{0.4(1-0.4)}{100}}$$
$$IC = 0.4 \pm 1.96 \cdot \sqrt{\frac{0.4(0.6)}{100}}$$
$$IC = 0.4 \pm 1.96 \cdot \sqrt{\frac{0.24}{100}}$$
$$IC = 0.4 \pm 1.96 \cdot \sqrt{0.0024}$$
$$IC = 0.4 \pm 1.96 \cdot 0.049$$
$$IC = 0.4 \pm 0.096$$  

8- O salário dos empregados das indústrias siderúrgicas tem distribuição normal, com média de 4,5 salários mínimos, com desvio padrão de 0,5 salário mínimo. Uma indústria emprega 49 empregados, com um salário médio de 4,3 salários mínimos. Ao nível de 5%, podemos afirmar que essa indústria paga salários inferiores à média?

> entra diretamente 5% pois é nivel de significancia, e o nivel de confiança é de 95% ou seja, 0.95

$\alpha = 0.05$

$p = \frac{40}{100} = 0.4$

$Z_{\alpha/2} = z_{0.025} = 1.96$

$IC = \bar{x} \pm Z_{\alpha/2} \cdot \frac{\sigma}{\sqrt{n}}$