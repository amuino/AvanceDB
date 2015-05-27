#ifndef REST_SERVER_H
#define	REST_SERVER_H

#include "libhttpserver.h"

class RestServer {
public:
    
    RestServer();
    void RouteRequest(rs::httpserver::socket_ptr socket, rs::httpserver::request_ptr request, rs::httpserver::response_ptr response);
    
private:
    
    bool GetUuids(rs::httpserver::request_ptr request, const rs::httpserver::RequestRouter::CallbackArgs&, rs::httpserver::response_ptr response);
    bool GetSession(rs::httpserver::request_ptr request, const rs::httpserver::RequestRouter::CallbackArgs&, rs::httpserver::response_ptr response);
    bool GetAllDbs(rs::httpserver::request_ptr request, const rs::httpserver::RequestRouter::CallbackArgs&, rs::httpserver::response_ptr response);
    bool GetSignature(rs::httpserver::request_ptr request, const rs::httpserver::RequestRouter::CallbackArgs&, rs::httpserver::response_ptr response);
    
    rs::httpserver::RequestRouter router_;        

};

#endif	/* REST_SERVER_H */
