mod fns;
mod fns_c;
mod fns_shared;

mod messages_c;
mod messages_h;

mod nodes_c;
mod nodes_h;

mod node_rs;

pub(crate) fn codegen() {
    messages_h::codegen();
    messages_c::codegen();

    nodes_h::codegen();
    nodes_c::codegen();

    node_rs::codegen();
}
