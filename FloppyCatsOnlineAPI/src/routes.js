import Router from 'koa-router'
import stunRoutes from './stun/index.js'

const router = new Router()

router.use('/stun', stunRoutes)

export default router.routes()
