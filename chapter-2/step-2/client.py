import socket

SERVER_HOST = "127.0.0.1"
SERVER_PORT = 18080
MAX_BUFFER_SIZE = 1024

if __name__ == "__main__" :

    try :
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect((SERVER_HOST, SERVER_PORT))
        print(f"[Client] Connected to server {SERVER_HOST}:{SERVER_PORT}")
    
        while True :

            message = input("> ")
            client_socket.send(message.encode("utf-8"));

            if message.lower() == "!quit" or message.lower() == "!q":
                break

            response = client_socket.recv(MAX_BUFFER_SIZE).decode("utf-8")
            print(f"[Server] {response}")
    except KeyboardInterrupt:
        print(f"[Client] Closing client")
    finally :
        #Libération du socket et donc du port associé
        client_socket.close()
        print("Connection closed.")