# ---------- Importações ----------
from multiprocessing import Process, Queue
from time import sleep

# ---------- Worker: verifica números primos ----------
def prime_worker(queue):
    # Inicializa contador local
    number = 2
    while number <= MAX_NUMBER:
        if number is primo:          # lógica simples de verificação de primo
            queue.put(1)             # envia incremento para o main
        number += 1

# ---------- Processo principal ----------
def main():
    # Inicializa fila de comunicação
    queue = Queue()

    # Inicializa contador de primos encontrados
    primes_found = 0

    # Cria e inicia o processo worker
    worker_process = Process(target=prime_worker, args=(queue,))
    worker_process.start()

    # Loop principal
    while primes_found < MAX_PRIMES:   # limite de demonstração
        sleep(1)                        # espera 1 segundo
        # Verifica a fila e atualiza contador
        while not queue.empty():
            primes_found += queue.get()
        # Calcula percentual (ex.: primes_found / MAX_PRIMES * 100)
        print(f"Progresso: {primes_found}/{MAX_PRIMES}")

    # Finaliza worker
    worker_process.terminate()

# ---------- Início do programa ----------
if __name__ == "__main__":
    main()
