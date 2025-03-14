#!/usr/bin/python3

"""
Request with cURL 
"""

import json
from http.server import BaseHTTPRequestHandler, HTTPServer

SERVER_IP = "127.0.0.1"
SERVER_PORT = 18080

class RequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path == '/':
            self.send_json_response(200, {"message": "Welcome to my API!"})
        else :
            self.send_json_response(404, {"error": "Not found"})
    
    def send_json_response(self, status_code, data):
        """Send a JSON response to the client"""
        self.send_response(status_code)
        self.send_header("Content-Type", "application/json")
        self.end_headers()
        self.wfile.write(json.dumps(data).encode("utf8"))

def run_server():
    """Initialise the server and start it"""

    server_address = (SERVER_IP, SERVER_PORT)
    server = HTTPServer(server_address, RequestHandler)

    print(f"Starting server in {SERVER_IP}:{SERVER_PORT}, use <Ctrl-C> to exit")

    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("Shutting down server...")
        server.server_close()


if __name__ == '__main__':
    run_server()