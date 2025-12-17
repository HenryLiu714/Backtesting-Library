#pragma once

#include <string>

class Event {
    public:
        Event() = default;
        virtual ~Event() = default;

        virtual std::string get_type() const = 0;
};

class MarketEvent: public Event {
    public:
        MarketEvent() = default;
        ~MarketEvent() override = default;

        std::string get_type() const override {
            return "MARKET";
        }
};

class SignalEvent: public Event {
    public:
        SignalEvent(const std::string& symbol, const std::string& signal_type, double strength)
            : symbol(symbol), signal_type(signal_type), strength(strength) {}
        ~SignalEvent() override = default;

        std::string get_type() const override {
            return "SIGNAL";
        }

        std::string symbol;       // e.g., "AAPL"
        std::string signal_type;  // e.g., "BUY" or "SELL"
        double strength;         // e.g., confidence level
};

class OrderEvent: public Event {
    public:
        OrderEvent(const std::string& symbol, const std::string& order_type, int quantity, double price)
            : symbol(symbol), order_type(order_type), quantity(quantity), price(price) {}
        ~OrderEvent() override = default;

        std::string get_type() const override {
            return "ORDER";
        }

        std::string symbol;      // e.g., "AAPL"
        std::string order_type;  // e.g., "MARKET" or "LIMIT"
        int quantity;           // e.g., number of shares
        double price;          // e.g., limit price
};

class FillEvent: public Event {
    public:
        FillEvent(const std::string& symbol, const std::string& exchange, int quantity, double price, double commission)
            : symbol(symbol), exchange(exchange), quantity(quantity), price(price), commission(commission) {}
        ~FillEvent() override = default;

        std::string get_type() const override {
            return "FILL";
        }

        std::string symbol;    // e.g., "AAPL"
        std::string exchange;  // e.g., "NASDAQ"
        int quantity;         // e.g., number of shares filled
        double price;        // e.g., fill price
        double commission;   // e.g., commission paid
};

