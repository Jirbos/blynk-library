/**
 * @file       BlynkSimpleYun.h
 * @author     Volodymyr Shymanskyy
 * @date       Mar 2015
 * @brief
 *
 */

#ifndef BlynkSimpleYun_h
#define BlynkSimpleYun_h

#include <Blynk/BlynkProtocol.h>
#include <BlynkArduinoClient.h>
#include <YunClient.h>

typedef BlynkArduinoClient BlynkArduinoClientYun;

class BlynkYun
    : public BlynkProtocol< BlynkArduinoClientYun >
{
    typedef BlynkProtocol< BlynkArduinoClientYun > Base;
public:
    BlynkYun(BlynkArduinoClientYun& conn)
        : BlynkProtocol< BlynkArduinoClientYun > (conn)
    {}

    void begin(const char* auth,
               const char* domain = BLYNK_DEFAULT_DOMAIN,
               uint16_t port      = BLYNK_DEFAULT_PORT)
    {
        Base::begin(auth);
        BLYNK_LOG("Bridge init...");
        Bridge.begin();
        this->conn.begin(domain, port);
    }

    void begin(const char* auth,
               IPAddress ip,
               uint16_t port)
    {
        Base::begin(auth);
        BLYNK_LOG("Bridge init...");
        Bridge.begin();
        this->conn.begin(ip, port);
    }

};

static YunClient _blynkYunClient;
static BlynkArduinoClient _blynkTransport(_blynkYunClient);
BlynkYun Blynk(_blynkTransport);

#include <BlynkWidgets.h>

#endif
