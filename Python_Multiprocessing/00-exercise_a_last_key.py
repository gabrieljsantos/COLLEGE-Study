

def main():
    last_key = "None"
    exit_key = ["exit", "EXIT", "Exit", "EXit"]
    count_inputs = 0

    while(last_key not in exit_key):
        print("Digite um valor : \n \n")
        last_key = input()
        count_inputs += 1
        print(f"\n\na ultima entrada foi {last_key}\n")
    
    print(f"dessa forma saiu do ciclo apois {count_inputs}")


if __name__ == "__main__":
    main()