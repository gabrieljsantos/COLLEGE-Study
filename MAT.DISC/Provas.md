>Sabe-se que Pinóquio ao passar por um bosque respondeu exatamente 20 perguntas. Para cada mentira seu nariz crescia 5 cm e para cada verdade seu nariz diminuía 3 cm. Em dois momentos seu nariz havia crescido 22 cm. Quais foram esses momentos?

>Obs: Obrigatório resolver por Congruência


Determinando a equação que define o tamanho do nariz: 
$$3$$
$$5m-3v=22$$

isolar

$$5m=22+3v$$

para sumir com 3v eu aplico mod 3:


$$2m=1+0 \pmod{3}$$




>Ache os números entre 1 e 100, inclusive, que são congruentes a 6 modulus 13 (2,0 Pts).

$$x \equiv 6 \pmod{13}$$

Primeiro vamos reescrever como equação:

$$x =k*13 +6$$

Determinar os termos das duas extremidades.
pela equação anterior, temos $x =k*13 +6$, que para encontar o maior valor e mais proximo a 1 para x, deve ser feito:

$$k_0*13 +6\geq 1$$

$$k_0\geq \frac{1 - 6}{13} =-0,38$$

porem k é inteiro, logo teremos que para está acima de 1, o minimo valor de $k_0$ deve ser 0

O tambem pode ser feito para o valor maximo do intervalo:

$$k_1*13 +6\leq 100$$

$$k_1\leq \frac{100 - 6}{13} =7,23$$

tambem nesse caso $k_1$ é inteiro e fica 7.
Calculando para todo intervalo encontrado:

$$6 = 0*13 + 6$$

$$19 = 1*13 + 6$$

$$32 = 2*13 + 6$$

$$45 = 3*13 + 6$$

$$58 = 4*13 + 6$$

$$71 = 5*13 + 6$$

$$84 = 6*13 + 6$$

$$97 = 7*13 + 6$$

Dessa forma, os números entre 1 e 100, inclusive, que são congruentes a 6 modulus 13, são:

$${6,19,32,45,58,71,84.97}$$

>Um grupo de pessoas gastou R\$ 1000 reais em um teatro. Sabendo-se que cada homem gastou R\$ 19 reais e cada mulher gastou R\$ 13 reais, e que apenas alguns homens estavam acompanhados pelas esposas, determine quantos homens e quantas mulheres estavam no teatro. A resolucao deve ser feita utilizando congruencia.

$$19H+13M=1000$$
$$
$$ para eu resolver

>crie uma versão mais basica de Resolva as seguintes equações de congruência: 
a) $$4x ^ 4 - 3x ^ 3 + 2x ^ 2 + 5x -4 \equiv 0 \pmod{6}$$ 

fazer redução módulo 6:

$$4x ^ 4 + 3x ^ 3 + 2x ^ 2 + 5x -4 \equiv 0 \pmod{6}$$ 



Um grupo de pessoas gastou R$ 1000 reais em um teatro. Sabendo-se que apenas alguns dos homens estavam acompanhados pelas esposas e que cada homem gastou R$ 19,00 reais e que cada mulher gastou R$ 13,00 reais. Determine: quantos homens e quantas mulheres estavam no teatro?
Obs: Obrigatório resolver por Congruência [2,5 Pts].

modelagem 
19h+13m=1000
faz mod 13
6h=12 (mod 13)
mdc(13,6) = 1
então posso fazer:
6x equi 1 mod 13
testar qual valor chega nisso
11
dessa forma, 11 é o valor que eu passo pro outro lado
11*6h=11*12 (mod 13)
ou seja, qual numero multiplicando os dois lado, o h sobra pra ele resto 1
h equi 2 mod 13
formula geral
h = 2 + 13k , k pertence a Z
subistituindo:
19h+13m=1000
19(2 + 13k)+13m=1000
