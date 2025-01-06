import { useState, useEffect } from 'react';
import axios from 'axios';

interface Order {
	id: number;
	cart: number;
}

interface Cart {
	id: number;
	customer: string;
	category: string;
	price: string;
	service: number;
}

interface OrderDetail extends Order {
	cartDetail: Cart | null;
}

const Orders: React.FC = () => {
	const [orders, setOrders] = useState<Order[]>([]);
	const [carts, setCarts] = useState<Cart[]>([]);
	const [orderDetails, setOrderDetails] = useState<OrderDetail[]>([]);

	// Fetch Orders
	const fetchOrders = async () => {
		try {
			const response = await axios.get<Order[]>('https://household-backend-a4k7.onrender.com/orders/order/');
			setOrders(response.data);
		} catch (error) {
			console.error(error);
		}
	};

	// Fetch Carts
	const fetchCarts = async () => {
		try {
			const response = await axios.get<Cart[]>('https://household-backend-a4k7.onrender.com/orders/cart/');
			setCarts(response.data);
		} catch (error) {
			console.error(error);
		}
	};

	
	useEffect(() => {
		const combinedOrderDetails: OrderDetail[] = orders.map(order => {
			const cartDetail = carts.find(cart => cart.id === order.cart) || null;
			return {
				...order,
				cartDetail, 
			};
		});
		setOrderDetails(combinedOrderDetails);
	}, [orders, carts]);


	useEffect(() => {
		fetchOrders();
		fetchCarts();
	}, []);

	console.log(orderDetails);


	return (
		<div>
			<table className="w-full text-sm text-left rtl:text-right text-gray-500 dark:text-gray-400">
				<thead className="text-xs text-gray-700 uppercase bg-gray-50 dark:bg-gray-700 dark:text-gray-400">
					<tr>
						<th scope="col" className="p-4">
							#OrderId
						</th>
						<th scope="col" className="px-6 py-3">
							#Cart Id
						</th>
						<th scope="col" className="px-6 py-3">
						Customer
						</th>
						<th scope="col" className="px-6 py-3">
						Category
						</th>
						<th scope="col" className="px-6 py-3">
						Price
						</th>
						<th scope="col" className="px-6 py-3">
						Total Order
						</th>
					</tr>
				</thead>
				<tbody>


					{
						orderDetails.map(order =>
							<tr key={order?.id} className=" bg-white border-b dark:bg-gray-800 dark:border-gray-700 hover:bg-gray-50 dark:hover:bg-gray-600">
								<td className="w-4 p-4">
									{order?.id}
								</td>
								<td className="px-6 py-4">
									{order?.cart}
								</td>
								{order.cartDetail ? (
									<>
									<td className="px-6 py-4">
										{order.cartDetail.customer}
									</td>
									<td className="px-6 py-4">
									{order.cartDetail.category}
									</td>
									<td className="px-6 py-4">
									{order.cartDetail.price}
									</td>
									<td className="px-6 py-4">
									{order.cartDetail.service}
									</td>
									</>
								) : (
									<p>Cart details not found</p>
								)}

							</tr>


						)
					}


				</tbody>
			</table>

		</div>
	);
};

export default Orders;
