import socket

SERVER_HOST = "127.0.0.1"
SERVER_PORT = 18080
MAX_BUFFER_SIZE = 1024

if __name__ == "__main__":
    server_socket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind((SERVER_HOST, SERVER_PORT))
    server_socket.listen()

    clients = []
    print(f"[Server] Start listeting on {SERVER_HOST}:{SERVER_PORT}...")

    try :
        while True:
            client_socket, client_adress = server_socket.accept()
            print(f"Accepted connexion from {client_adress}")
            clients.append(client_socket)

            while True:
                print(f"[Server] Waiting for message from {client_adress}...")
                try:
                    message = client_socket.recv(MAX_BUFFER_SIZE).decode("utf-8")
                    if not message:
                        break
                    print(f"[Client {client_adress}] Recived message: {message}")
                except ConnectionResetError:
                    break
    except KeyboardInterrupt:
        print(f"\n[Server] Shutdown server...")
    finally :
        for client in clients:
            client.close()
        server_socket.close()
        print("[Server] Shutdown complete")