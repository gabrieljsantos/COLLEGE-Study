# Noções de Probabilidade

## Conceitos Básicos

>  6- De um grupo de 12 homens e 8 mulheres, retiram-se
4 pessoas para formar uma comiss˜ao. Qual a probabili-
dade de:

>a) pelo menos uma mulher fazer parte da comiss˜ao?

total : $${C(12+8,4) = \frac{20\times 19 \times 18 \times 17}{4 \times 3 \times 2 \times 1} = T}$$
mulher : 
$${C(8,4) = \frac{8\times 7 \times 6 \times 5}{4 \times 3 \times 2 \times 1} =M}$$
homem:
$${C(12,4) = \frac{12\times 11 \times 10 \times 9}{4 \times 3 \times 2 \times 1} =H}$$

$${P(no minimo uma 1mulher) = 1 - \frac{H}{T}}$$

>b) uma mulher fazer parte da comiss˜ao?

$${C(uma.mulher.so..ou.8,1) = 8}$$
$${C(tres.homens..12,3) = \frac{12\times 11 \times 10}{3 \times 2 \times 1} =H_3 }$$
$${C(uma.mulher.so) = 8\times H_3 =C_{H3}}$$
$${P(C_{H3}) = \frac{C_{H3}}{T}}$$

>c) haver pessoas dos dois sexos na comiss˜ao?


$${P(homem.mulher) =  1-\frac{M-H}{T}}$$