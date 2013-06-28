
class LayerProxy {
/* A proxy for a Layer. */

};

class CommandProxy {
/* used in command queues to reference the next command */
    void next(Command* previous_command);
};

class Command {
/* Commands are sent to NeuralReactors to perform async actions. */
    std::vector<CommandProxy*> _next;
    virtual void execute(NeuralReactor* neural_reactor) = 0;
};

class FeedForward : public Command {
/* Prototype feedforward command */
    LayerProxy _this_layer;
    char _rank; // worker, manager, director
    void execute(NeuralReactor& neural_reactor) {
        neural_reactor.
        neural_reactor.put(msg);
        neural_reactor.push(this);
    };
};

class SessionInitiator : public ThreadActor {
/* Initiates sessions 
 * Example:
 * feedforward X0 through Layer L1 -> X1
 * feedforward X1 through Layer L2 -> X2 
 * feedforward X2 through Layer L3 -> X3 */
};

class SessionState {
/* keeps track of a session's state in an actor. */
    int _state;
    int getState() {
        return _state;
    };
};

class NeuralReactor : public ThreadActor {
/* reacts to requests from other NeuralReactors or SessionInitiators.
 * Handles both map and reduce. 
 * An NeuralReactor as 3 queues: 
 *  an internal PriorityQueue for sending messages to itself;
 *  an external PriorityQueue for receiving messages from others;
 *  a dedicated GPU stream for receiving events from the GPU;
 *  a dedicated PostgreSQL pipe for receiving results from disk */
    std::unordered_map<hash_t, SessionState*> _session_map;
    std::unordered_map<hash_t, NDArray*> _ndarray_map;
    SessionState* getSessionState(ID session_id) {
        /* Get session state from session state map */
        return ss;
    };
    void handle_activate(ID session_id, ValueArray* sum_array) {
        SessionState* ss = getSessionState(session_id);
    };
    void handle_command(Command* cmd) {
        cmd->execute(this);
    };
    void handle_message(Message* msg) {
        std::string msg_type = msg->getType();
        // message handler
    };
    void handle_gpu_event(Event* event) {
        
    };
    void run() {
        Message* msg = _get_queue.get(no_wait);
        if (!_cmd_queue.empty()) {
            Command* cmd = _cmd_queue.get(no_wait);
        };
        if (!_gpu_queue_empty) {
            Event* event = _gpu_queue.get(no_wait);
        };
    };
};
