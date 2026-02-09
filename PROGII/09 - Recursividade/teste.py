def exemplo(n):
    print(f"Entrou na função com n = {n}")

    if n == 0:
        print("Caso base atingido")
        return

    exemplo(n - 1)

    print(f"Voltando da função com n = {n}")

exemplo(3)
