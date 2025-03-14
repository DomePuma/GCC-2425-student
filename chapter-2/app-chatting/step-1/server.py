import socket

SERVER_HOST = "127.0.0.1"
SERVER_PORT = 18080
MAX_BUFFER_SIZE = 1024

if __name__ == "__main__":
    #Création d'un socket (IPv4, TCP)
    server_socket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    #On associe le socket à un port donné sur une adresse IP fixée à localhost
    server_socket.bind((SERVER_HOST, SERVER_PORT))

    #Mise ne écoute du serveur, donc en attente de connexions
    server_socket.listen()

    #Accepter une connexion
    client_socket, client_address = server_socket.accept()
    print(f"Accepted connexion from {client_address}")

    #Recevoir un message de la part du client
    message = client_socket.recv(MAX_BUFFER_SIZE).decode("utf-8")
    print(f"Recived message: {message}")

    #Répond au client
    client_socket.send("Message well recived!".encode("utf-8"))

    #Ferme la connexion et on libère les sockets
    client_socket.close()
    server_socket.close()
    print("Connexion Closed")